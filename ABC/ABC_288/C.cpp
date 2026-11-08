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

    bool unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);

        if (rx == ry) return false;
        p[rx] = ry;

        return true;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};


int main() {
    int N, M;
    std::cin >> N >> M;

    int ans = 0;

    UnionFind uf(N);
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;

        if (!uf.unite(u, v)) {
            ++ans;
        }
    }
    std::cout << ans << '\n';

    return 0;
}

