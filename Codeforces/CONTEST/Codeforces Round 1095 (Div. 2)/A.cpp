#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 676767677;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    
    ll ans = 0;
    int lastBig = -1;
    for(int i = 0; i < n; i++){
        if(a[i] >= 2){
            ans = (ans + a[i]) % MOD;
            lastBig = i;
        }
    }
    
    if(lastBig == -1){
        bool anyOne = false;
        for(int x : a) if(x == 1) anyOne = true;
        if(anyOne) ans = (ans + 1) % MOD;
    } else {
        bool oneAfter = false;
        for(int i = lastBig + 1; i < n; i++){
            if(a[i] == 1){ oneAfter = true; break; }
        }
        if(oneAfter) ans = (ans + 1) % MOD;
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