#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    // items n, firends m
    int N, M;
    cin >> N >> M;
    
    // sum of items in array
    ll totalBill = 0;
    for(int i = 0; i < N; i++){
        int p;
        cin >> p;
        totalBill += p;
    }
    // check if 
    ll totalPaid = 0;
    for(int j = 0; j < M; j++){
        int a;
        cin >> a;
        totalPaid += a;
    }
    
    // rounded tip
    ll tip = (totalBill + 9) / 10;
    ll required = totalBill + tip;
    
    if(totalPaid >= required) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}