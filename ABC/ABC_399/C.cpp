#include <bits/stdc++.h>

struct UnionFind {
    std::vector<int> p; // parent

    UnionFind(int N) : p(N) {
        for (int i = 0; i < N; i++) p[i] = i;
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
    // input
    int N, M;
    std::cin >> N >> M;

    UnionFind uf(N);
    
    int ans = 0;
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;

        if (uf.same(u, v)) ans++;
        else uf.unite(u, v);
    }

    // presentation
    std::cout << ans << std::endl;

        
    return 0;
}

