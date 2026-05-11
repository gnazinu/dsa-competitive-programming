#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    ll initial_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        initial_sum += 1LL * i * a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    ll sorted_sum = 0;
    for (int i = 0; i < n; i++) {
        sorted_sum += 1LL * i * b[i];
    }

    ll base = sorted_sum - initial_sum;

    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + b[i];
    }

    ll ans = base;

    for (int i = 0; i < n; i++) {
        int x = a[i];

        int l = lower_bound(b.begin(), b.end(), x) - b.begin(); 
        int r = lower_bound(b.begin(), b.end(), x - 1) - b.begin();

        ll new_sorted = sorted_sum;

        new_sorted -= 1LL * l * x;
        new_sorted += (pref[l] - pref[r]);
        new_sorted += 1LL * r * (x - 1);

        ll new_initial = initial_sum - i;

        ans = max(ans, new_sorted - new_initial);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}