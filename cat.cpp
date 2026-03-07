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

