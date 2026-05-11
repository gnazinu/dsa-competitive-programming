#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

struct BIT {
    int n;
    vector<int> t;
    BIT(int n) : n(n), t(n + 1, 0) {}
    void upd(int i, int d) {
        for (; i <= n; i += i & -i) t[i] += d;
    }
    int qry(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += t[i];
        return s;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + (i % 2 ? a[i] : -a[i]);
    }

    vector<int> v = p;
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    auto id = [&](int x) {
        return lower_bound(all(v), x) - v.begin() + 1;
    };

    int k = v.size();
    BIT b0(k), b1(k);
    
    b0.upd(id(p[0]), 1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int curr = id(p[i]);
        if (i % 2) {
            ans += b0.qry(curr - 1);
            b1.upd(curr, 1);
        } else {
            ans += b1.qry(k) - b1.qry(curr);
            b0.upd(curr, 1);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}