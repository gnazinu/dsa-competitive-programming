#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    int m = 2 * n;
    vector<int> a(m);
    int p1 = -1, p2 = -1;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            if (p1 == -1) p1 = i;
            else p2 = i;
        }
    }

    int res = 0;
    vector<pair<int, int>> centers = {{p1, p1}, {p2, p2}, {(p1 + p2) / 2, (p1 + p2 + 1) / 2}};

    for (auto& c : centers) {
        int l = c.first, r = c.second;
        while (l >= 0 && r < m && a[l] == a[r]) {
            l--; r++;
        }
        l++; r--;

        if (l <= r) {

            vector<int> sub;
            for (int i = l; i <= r; i++) sub.push_back(a[i]);
            sort(sub.begin(), sub.end());
            sub.erase(unique(sub.begin(), sub.end()), sub.end());
            
            int cur_mex = 0;
            for (int val : sub) {
                if (val == cur_mex) cur_mex++;
                else break;
            }
            res = max(res, cur_mex);
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}