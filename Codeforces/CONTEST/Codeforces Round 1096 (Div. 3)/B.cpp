#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    string s;
    cin >> n >> s;

    if (n % 2 != 0) {
        cout << "NO\n";
        return;
    }

    int pcount = count(s.begin(), s.end(), '(');

    if (pcount == n / 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t; 
    while(t--) solve();
    
    return 0;
}