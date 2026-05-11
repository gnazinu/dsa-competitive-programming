// 158A - Next Round
// Explanation: We need to determine how many participants will advance to the next round based on their scores. The participants with scores greater than or equal to the k-th participant's score will advance,

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    int threshold = scores[k - 1];
    int count = 0;
    for (int score : scores) {
        if (score >= threshold && score > 0) {
            count++;
        }
    }
    cout << count << endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}