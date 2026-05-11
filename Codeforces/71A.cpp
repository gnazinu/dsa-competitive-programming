//71A - Way Too Long Words
// Sometimes some words like "localization" are long, so people just abbreviate them as "l10n", where 10 stands for the number of letters between the first and the last letter. 


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s; cin>>s;
    if(s.size()>10) cout<<s[0]<<s.size()-2<<s[s.size()-1]<<"\n";
    else cout<<s<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}