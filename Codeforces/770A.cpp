#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;

    string res = "";
    
    for(int i = 0; i < n; i++){
        res += char('a' + (i % k));
    }

    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}