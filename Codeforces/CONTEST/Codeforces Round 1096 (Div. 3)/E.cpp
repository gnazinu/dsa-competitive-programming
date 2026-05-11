#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    ll total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    // suf minimo
    vector<int> suf(n);
    suf[n - 1] = a[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        suf[i] = min(a[i], suf[i + 1]);
    }

    ll fixed = 0;
    for (int x : suf) fixed += x;

    ll base = total - fixed;

    ll best_gain = 0;

    // guardamos primera posicion
    unordered_map<int, int> first;

    for (int i = n - 1; i >= 0; i--) {
        first[suf[i]] = i;
    }

    for (int k = 0; k < n; k++) {
        int val = a[k];

        if (val == 0) continue;

        int leftmost = k;

        if (first.count(val)) {
            leftmost = first[val];
        }

        ll gain = k - leftmost + 1;

        best_gain = max(best_gain, gain);
    }

    cout << base + best_gain - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}