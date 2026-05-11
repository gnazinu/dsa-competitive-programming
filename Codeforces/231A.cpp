//231A - Team
// The problem is to determine how many teams of three students can be formed such that at least two of the students in the team are friends.

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    if (!(cin >> n)) return;
    
    int implemented_problems = 0;
    while(n--){
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2) {
            implemented_problems++;
        }
    }
    cout << implemented_problems << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}