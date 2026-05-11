#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int x, y;

    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            int val;
            cin >> val;
            if(val == 1){
                x = i;
                y = j;
            }
        }
    }

    cout << abs(x - 3) + abs(y - 3) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}