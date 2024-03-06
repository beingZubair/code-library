#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2e5 + 5;
    
int a[maxn];
int64_t tree[4 * maxn];
int64_t lazy[4 * maxn];

struct Lazy {
    inline void combine(int node) {
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    inline void propagate(int node, int b, int e) {
        if (lazy[node] == 0) return;
        tree[node] = tree[node] + lazy[node] * (e - b + 1); // change
        if (b != e) {
            lazy[2 * node] += lazy[node]; // change
            lazy[2 * node + 1] += lazy[node]; // change
        }
        lazy[node] = 0;
    }

    void build(int node, int b, int e) {
        lazy[node] = 0;
        if (b == e) {
            tree[node] = a[b];
            return;
        }
        int mid = b + e >> 1;
        build(2 * node, b, mid);
        build(2 * node + 1, mid + 1, e);
        combine(node); // change
    }

    void update(int node, int b, int e, int i, int j, int val) {
        propagate(node, b, e);
        if (i > e or j < b) return;
        if (b >= i and e <= j) {
            lazy[node] = val; // change
            propagate(node, b, e);
            return;
        }
        int mid = b + e >> 1;
        update(2 * node, b, mid, i, j, val);
        update(2 * node + 1, mid + 1, e, i, j, val);
        combine(node); // change
    }

    int64_t query(int node, int b, int e, int i, int j) {
        propagate(node, b, e);
        if (i > e or j < b) return 0;
        if (b >= i and e <= j) return tree[node];
        int mid = b + e >> 1;
        return query(2 * node, b, mid, i, j) + query(2 * node + 1, mid + 1, e, i, j); // change
    }
} lz;

int main() {
  return 0;
}
