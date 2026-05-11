#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    
    int small_val = 1;
    int large_val = n + 1;

    for (int i = 0; i < n; ++i) {
        cout << small_val++ << " " << large_val++ << " " << large_val++ << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}