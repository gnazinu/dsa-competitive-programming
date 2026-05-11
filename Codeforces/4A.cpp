// 4A - Watermelon
// Print YES, if the boys can divide the watermelon into two parts, each of them weighing even number of kilos; and NO in the opposite case.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int w; cin>>w;
    if(w%2==0 && w!=2) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}