#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_NODES = 9000005; 
int trie_tree[MAX_NODES][2];
int trie_sz = 1;

inline void insert(int x) {
    int u = 1;
    for (int i = 29; i >= 0; i--) {
        int bit = (x >> i) & 1;
        if (!trie_tree[u][bit]) {
            trie_tree[u][bit] = ++trie_sz;
            trie_tree[trie_sz][0] = trie_tree[trie_sz][1] = 0; 
        }
        u = trie_tree[u][bit];
    }
}

inline int query(int x) {
    int u = 1;
    int ans = 0;
    for (int i = 29; i >= 0; i--) {
        int bit = (x >> i) & 1;
        int req = bit ^ 1; 
        
        if (trie_tree[u][req]) {
            ans |= (1 << i);
            u = trie_tree[u][req];
        } else {
            u = trie_tree[u][bit];
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;

    trie_tree[1][0] = trie_tree[1][1] = 0;
    trie_sz = 1;

    int max_xor = 0;
    
    int first_val;
    cin >> first_val;
    insert(first_val);

    for (int i = 1; i < n; i++) {
        int val;
        cin >> val;
        max_xor = max(max_xor, query(val));
        insert(val);
    }
    
    cout << max_xor << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}