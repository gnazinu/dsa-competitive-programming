#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> getCanonicalForm(int n) {
    vector<int> factors;
    for(int i = 2; (ll)i * i <= n; i++) {
        while(n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if(n > 1) factors.push_back(n);
    return factors;
}

void solve(){
    int N, Q;
    cin >> N >> Q;

    vector<pair<vector<int>, int>> numbers;
    for(int i = 1; i <= N; i++) {
        numbers.push_back({getCanonicalForm(i), i});
    }

    sort(numbers.begin(), numbers.end());

    vector<int> order;
    for(auto& p : numbers) {
        order.push_back(p.second);
    }

    while(Q--) {
        int k;
        cin >> k;
        cout << order[k - 1] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--) solve();
    return 0;
}
