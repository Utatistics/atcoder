#include <bits/stdc++.h>

struct UnionFind {
    std::vector<int> p;

    UnionFind(int N) : p(N) {
        for (int i = 0; i < N; i++) p[i] = i;
    }

    int root(int x) {
        if (p[x] == x) return x;
        return p[x] = root(p[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);

        if (rx == ry) return;
        p[rx] = ry;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

int main() {
    int N, M;
    std::cin >> N >> M;

    UnionFind uf(N);

    int x = 0;

    for (int i = 0; i < M; i++) { // O(M * α(N))
        int a, c;
        char b, d;
        std::cin >> a >> b >> c >> d;
        --a; --c;

        if (uf.same(a, c)) ++x; 
        else uf.unite(a, c);
    }

    int components = 0;
    for (int i = 0; i < N; i++) { // O(N * α(N))
        if (uf.root(i) == i) ++components;
    }

    int y = components - x;
    std::cout << x << " " << y << '\n';

    return 0;
}

