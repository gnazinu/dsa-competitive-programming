#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll get_value(vector<int>& a){
    ll sum = 0;
    int cur_max = 0;

    for(int x : a){
        cur_max = max(cur_max, x);
        sum += cur_max;
    }

    return sum;
}

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = get_value(a);

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            swap(a[i], a[j]);

            ans = max(ans, get_value(a));

            swap(a[i], a[j]);
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}