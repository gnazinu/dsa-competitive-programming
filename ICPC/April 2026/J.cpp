#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long power(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long inv(long long a) {
    return power(a, MOD - 2);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long even = n / 2;
        long long odd = (n + 1) / 2;

        long long ans = 0;

        if (even >= 3) {
            long long c3 = even % MOD * ((even - 1) % MOD) % MOD * ((even - 2) % MOD) % MOD * inv(6) % MOD;
            ans = (ans + c3) % MOD;
        }

        if (odd >= 2) {
            long long c2 = odd % MOD * ((odd - 1) % MOD) % MOD * inv(2) % MOD;
            long long term = even % MOD * c2 % MOD;
            ans = (ans + term) % MOD;
        }

        cout << ans << "\n";
    }

    return 0;
}