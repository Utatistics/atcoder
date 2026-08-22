#include <bits/stdc++.h>

using P = std::pair<int, int>;

int H, W;
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

int main() {
    int K;
    std::cin >> H >> W >> K;

    std::vector<std::vector<char>> S(H, std::vector<char>(W)); 
    std::vector<bool> r(H, true), c(W, true);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> S[i][j];
            if (S[i][j] == '#') {
                r[i] = false; 
                c[j] = false;
            }
        }
    }
    
    std::vector<P> s; 
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (r[i] && c[j]) s.emplace_back(i, j);
        }
    }

    std::vector<std::vector<int>> dist(H, std::vector<int>(W, -1)); 
    auto bfs = [&]() -> void {
        std::queue<P> q;

        for (auto p : s) { // init
            q.push(p);
            dist[p.first][p.second] = 0;
        }
        
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int ni = i + di[k]; int nj = j + dj[k];
                if (!isBound(ni, nj)) continue;
                if (S[ni][nj] == '#') continue;
                if (dist[ni][nj] >= 0) continue;
                dist [ni][nj] = dist[i][j] + 1;
                q.emplace(ni, nj);
            }
        }
    };
    bfs();

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (dist[i][j] < 0) continue;
            if (dist[i][j] <= K) ++ans;
        }
    }

    std::cout << ans << std::endl;
    

    return 0;
}

