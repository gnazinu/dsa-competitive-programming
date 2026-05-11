#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int MAX_P = 150000;
bool is_prime[MAX_P + 1];
ll primes[10005];
bool initialized = false;

void init_sieve() {
    fill(is_prime, is_prime + MAX_P + 1, true);
    for (int p = 2; p * p <= MAX_P; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX_P; i += p) {
                is_prime[i] = false;
            }
        }
    }
    primes[0] = 1; 
    int count = 1;
    for (int p = 2; p <= MAX_P && count <= 10002; ++p) {
        if (is_prime[p]) {
            primes[count++] = p;
        }
    }
}

void solve(){
    if (!initialized) {
        init_sieve();
        initialized = true;
    }
    
    int n; 
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cout << primes[i - 1] * primes[i] << (i == n ? "" : " ");
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