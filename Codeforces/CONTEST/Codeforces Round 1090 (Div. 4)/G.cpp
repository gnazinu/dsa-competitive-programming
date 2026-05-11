#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200005;
const ll MOD = 676767677;

int b[MAXN];
int freq[MAXN];
int prefix_S[MAXN];

void solve(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        freq[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        freq[b[i]]++;
    }

    prefix_S[0] = freq[0];
    for (int i = 1; i < m; ++i) {
        prefix_S[i] = prefix_S[i - 1] + freq[i];
    }

    ll ans = 1;

    for (int i = 0; i < n; ++i) {
        if (b[i] == 0) continue;

        int min_neighbor = 1e9;
        if (i > 0) min_neighbor = min(min_neighbor, b[i - 1]);
        if (i < n - 1) min_neighbor = min(min_neighbor, b[i + 1]);

        if (min_neighbor >= b[i]) {
            ans = 0;
            break; 
        } else if (min_neighbor == b[i] - 1) {
            ans = (ans * prefix_S[b[i] - 1]) % MOD;
        } else {
            ans = (ans * freq[b[i] - 1]) % MOD;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}