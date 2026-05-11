#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int sum = 0;
    int max_val = -100; 

    for (int i = 0; i < 7; ++i) {
        int a;
        cin >> a;
        sum += a;
        max_val = max(max_val, a);
    }

    cout << 2 * max_val - sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}