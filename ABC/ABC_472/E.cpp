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
    int T;
    std::cin >> T;

    while (T--) {
        int N, M;
        std::cin >> N >> M;
    
        UnionFind uf(N);
        for (int i = 0; i < M; i++) {
            int u, v;
            std::cin >> u >> v;
            --u; --v;

            if (uf.same(u, v)) continue;
            else uf.unite(u, v);
        }
        std::vector<std::vector<int>> par;
        for (int i = 0; i < N; i++) {
            par[uf.root(i)].push_back(i);
        }

        int ans = -1;
        for (auto p : par) {
            if ((int)p.size() % 2 != 0) {
                for (int v : p) {
                    std::cout << v << " ";
                }
            }

        }

        std::cout << ans << std::endl;
    }
    return 0;
}

