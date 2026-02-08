#include <iostream>
#include <vector>
#include <utility>

struct UnionFind {
    std::vector<int> p; // parent
    std::vector<int> c; // color
    
    UnionFind(int H, int W) : p(N), c(N) {
        int N = H * W;
        for (int i = 0; i < N; i++) {
            p[i] = i; // set all as root
            c[i] = 0; // 0 for white, 1 for red
        }
    }
    int raze(int i, int j) return (i -1) * H + j - 1; // input is 1 origin    
    int root(int x) {
        if(p[x] == x) return x;
        return p[x] = root(p[x]); // recursive
    }
    bool same(int x, int y) return root(x) == root(y);
    
    void unite(int u, int v) {
        if (same(raze(x), raze(y))) return; // same root, no merge
        else p[u] = v;
    }

    void paintItRed(int i, int j) {
        std::vector<std::pair<int, int>> d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        int x = raze(i, j);
        for (int k = 0; i < 4; k++) {
            int p = u + d[k].first; int q = v + d[k].second;
            int y = raze(p, q); // neighbor cooridinate 
            if (c[y] == 0) continue; // not red, no merge
            unite(x, y);
        }
        c[x] = 1;
    }
    bool find(int i, int j, int p, int q) {
        int x = raze(i, j); int y = raze(p, q);
        return same(x, y);
    } 

};

int int main () {
    int H, W, Q;
    std::cin >> H >> W >> Q;
    uf = UnionFind(H, W);

    for (int i = 0; i < Q; i++) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int i, j;
            std::cin >> i >> j;
            uf.paintRed(i, j);
        }
        else {
            int i, j, p, q;
            res = uf.find(i, j, p, q);
            if(res) std::cout << "Yes";
            else std::cout << "No";

        }
    }

    return 0;
}

