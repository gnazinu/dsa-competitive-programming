// 1A - Theatre Square
// Explation: Given the dimensions of the theatre square and the size of the flagstones, we need to calculate how many flagstones are needed to cover the entire square. 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m, a;
    cin >> n >> m >> a;
    ll x = (n + a - 1) / a;
    ll y = (m + a - 1) / a;
    cout << x * y << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}