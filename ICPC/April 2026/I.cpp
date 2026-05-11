#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;

    vector<int> b(n);

    // izq - der
    vector<int> ltr(n, 1);
    for(int i = 1; i < n; i++){
        if(s[i-1] == '<'){
            ltr[i] = ltr[i-1] + 1;
        } else if(s[i-1] == '='){
            ltr[i] = ltr[i-1];
        }
    }

    // der - izq
    vector<int> rtl(n, 1);
    for(int i = n-2; i >= 0; i--){
        if(s[i] == '>'){
            rtl[i] = rtl[i+1] + 1;
        } else if(s[i] == '='){
            rtl[i] = rtl[i+1];
        }
    }

    ll cost = 0;
    for(int i = 0; i < n; i++){
        b[i] = max(ltr[i], rtl[i]);
        cost += a[i] * b[i];
    }

    cout << cost << "\n";
    for(int i = 0; i < n; i++){
        if(i > 0) cout << " ";
        cout << b[i];
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}