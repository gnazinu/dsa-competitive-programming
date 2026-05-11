#include <iostream>
#include <cstdint>
#include <algorithm>

void solve() {
    int64_t p, q;
    std::cin >> p >> q;

    int64_t S = 2 * p + 4 * q + 1;

    for (int64_t A = 3; A * A <= S; A += 2) {
        if (S % A == 0) {
            int64_t B = S / A;
            
            int64_t n = (A - 1) / 2;
            int64_t m = (B - 1) / 2;

            int64_t max_L = std::min(n * (m + 1), m * (n + 1));
            
            if (q <= max_L) {
                std::cout << n << " " << m << "\n";
                return;
            }
        }
    }
    
    std::cout << -1 << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (std::cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}