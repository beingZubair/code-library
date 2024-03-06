#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2e5 + 5;

int a[maxn];
int64_t tree[4 * maxn];

struct SegTree {
    inline void combine(int node) {
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void build(int node, int b, int e) {
        if (b == e) {
            tree[node] = a[b]; // change
            return;
        }
        int mid = b + e >> 1;
        build(2 * node, b, mid);
        build(2 * node + 1, mid + 1, e); 
        combine(node); // change
    }

    void update(int node, int b, int e, int pos, int val) {
        if (pos > e or pos < b) return;
        if (b == e and pos == b) {
            tree[node] = val; // change
            return;
        }
        int mid = b + e >> 1;
        update(2 * node, b, mid, pos, val);
        update(2 * node + 1, mid + 1, e, pos, val);
        combine(node); // change
    }

    int64_t query(int node, int b, int e, int i, int j) {
        if (i > e or j < b) return 0; // return what?
        if (b >= i and e <= j) {
            return tree[node];
        }
        int mid = b + e >> 1;
        int p = query(2 * node, b, mid, i, j);
        int q = query(2 * node + 1, mid + 1, e, i, j);
        return p + q; // change
    }
} sg;

int main() {
  return 0;
}
