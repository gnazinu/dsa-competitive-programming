#include <bits/stdc++.h>
using namespace std;

class BIT {
    vector<int> tree;
    int n;
public:
    BIT(int n) : n(n), tree(n + 1, 0) {}

    void update(int i) {
        for (++i; i <= n; i += i & -i) tree[i]++;
    }

    int query(int i) {
        if (i < 0) return 0;
        int sum = 0;
        for (++i; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        cin >> perm[i];
    }

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int i;
            cin >> i;
            i--;
            swap(perm[i], perm[i + 1]);
        } else {
            int k;
            cin >> k;

            BIT bit(n);
            long long inv = 0;

            for (int i = n - 1; i >= 0; i--) {
                int val = perm[(i + k) % n] - 1;
                inv += bit.query(val - 1);
                bit.update(val);
            }

            cout << inv << "\n";
        }
    }

    return 0;
}