#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    
    vector<int> t6, t2, t3, t1;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        
        if (x % 6 == 0) t6.push_back(x);
        else if (x % 2 == 0) t2.push_back(x);
        else if (x % 3 == 0) t3.push_back(x);
        else t1.push_back(x);
    }
    
    // ordered
    for(int x : t6) cout << x << " ";
    for(int x : t2) cout << x << " ";
    for(int x : t1) cout << x << " ";
    for(int x : t3) cout << x << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}