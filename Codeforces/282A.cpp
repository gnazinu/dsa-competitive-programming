// 282A - Bit++
// The program must determine the final value of x after performing all the operations described in the input

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){

    int n; cin>>n;
    int x=0; // counter
    while(n--){
        string s; cin>>s; // read input
        if(s[1]=='+') x++;
        else x--;
    }
    cout<<x<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}