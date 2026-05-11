#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int x, y;
    cin >> x >> y;
    int n = x + y;

    if (x > y) {
        cout << "NO\n";
        return;
    }
    if (n % 2 == 0 && x == 0) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    
    int A, B;
    if (n % 2 == 0) {
        A = x - 1;
        B = y - x + 1;
    } else {
        A = x;
        B = y - x - 1;
    }

    int curr = 2;
    for (int i = 0; i < A; ++i) {
        cout << 1 << " " << curr << "\n";
        cout << curr << " " << curr + 1 << "\n";
        curr += 2;
    }
    for (int i = 0; i < B; ++i) {
        cout << 1 << " " << curr << "\n";
        curr++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}