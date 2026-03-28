#include <bits/stdc++.h>

using ll = long long;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

struct UnionFind {
    std::vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        
        return true;
    }
};

int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        std::cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    
    std::sort(edges.begin(), edges.end());

    UnionFind uf(V);
    ll ans = 0;

    for (auto &e : edges) {
        if (uf.unite(e.u, e.v)) {
            ans += e.w;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
