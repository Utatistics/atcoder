#include <bits/stdc++.h>

struct UnionFind {
    std::vector<int> p; // parent

    UnionFind(int N) : p(N) { // declare all nodes as root
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

int main () {
    // input
    int N;
    std::cin >> N;

    // solve
    UnionFind uf(N);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        a--; // 0 index
        uf.unite(i, a);
    }

    std::map<int, int> m;
    for (auto p : uf.p) m[p]++;

    // presentation
    int ans = 0;
    for (auto [p, c] : m) {
        if (c % 2 == 0) ans+= c /2;
        else {
            ans = -1;
            break;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
