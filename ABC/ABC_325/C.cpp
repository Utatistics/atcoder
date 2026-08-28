#include <bits/stdc++.h>

using P = std::pair<int, int>;

int H, W;

static const int di[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
static const int dj[8] = {0, 0, -1, 1, -1, 1, -1, 1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

int main() {
    std::cin >> H >> W;

    std::vector<std::string> G(H);
    for (int i = 0; i < H; i++) std::cin >> G[i];
    

    std::vector<std::vector<P>> C; // connected components
    std::vector<std::vector<int>> m(H,std::vector<int>(W, -1));
    auto bfs = [&](int si, int sj) -> void {
        if (m[si][sj] >= 0) return;

        int p = (int)C.size(); // ith cc
        std::vector<P> c; // cc nodes
        std::queue<P> q;

        m[si][sj] = p;
        c.emplace_back(si, sj);
        q.emplace(si, sj);

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();

            for (int k = 0; k < 8; k++) { // define adj list
                int ni = i + di[k]; int nj = j + dj[k];
                if (!isBound(ni, nj)) continue;
                if (G[ni][nj] == '.') continue;
                if (m[ni][nj] >= 0) continue;
                m[ni][nj] = p;
                c.emplace_back(ni, nj);
                q.emplace(ni, nj);
            }
            
        }
        C.push_back(c);
    };

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (G[i][j] == '.') continue;
            bfs(i, j);
        }
    }

    std::cout << (int)C.size() << std::endl;
    
    return 0;
}
