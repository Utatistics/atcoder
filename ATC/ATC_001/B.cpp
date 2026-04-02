#include <bits/stdc++.h>

struct UnionFind {
    std::vector<int> p; // parent

    UnionFind(int N) : p(N) {
        for (int i = 0; i < N; i++) p[i] = i; // declare all nodes as root
    }

    int root(int x) {
        if (p[x] == x) return x;
        return p[x] = root(p[x]);
    }

    void unite(int x, int y) {
        if (same(x, y)) return;
        p[root(x)] = root(y);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

int main() {
    int N, Q;
    std::cin >> N >> Q;

    UnionFind uf(N);

    while (Q--) {
        int t;
        std::cin >> t;

        int a, b;
        std::cin >> a >> b;
        if (t == 0) {
            uf.unite(a, b);
        }
        if (t == 1) {
            if (uf.same(a, b)) std::cout << "Yes\n";
            else std::cout << "No\n";
        }
    }

    return 0;
}

