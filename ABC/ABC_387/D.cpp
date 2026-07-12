#include <bits/stdc++.h>

using P = std::pair<int, int>;
struct U {int i; int j; int dir;};

// up, down, left, right
int H, W;
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

int main() {
    std::cin >> H >> W;

    std::vector<std::string> S(H);
    P s = {-1, -1}; 
    P g = {-1, -1};
    for (int i = 0; i < H; i++) {
        std::cin >> S[i];
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'S') {
                s.first = i;
                s.second = j;
            }
            if (S[i][j] == 'G') {
                g.first = i;
                g.second = j;
            }
        }
    }

    auto bfs = [&](int dir) -> int {
        std::queue<U> q;
        q.push({s.first, s.second, dir});
        std::vector<std::vector<int>> dist(H, std::vector<int>(W, -1)); // distance
        dist[s.first][s.second] = 0;

        while (!q.empty()) {
            auto [i, j, p] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];

                if (!isBound(ni, nj)) continue;
                if (S[ni][nj] == '#') continue;
                if (dist[ni][nj] > 0) continue;
                if (k / 2 == p / 2) continue;
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj, k});
            }
        }
        return dist[g.first][g.second];
    };

    int ans0 = bfs(0); // up or down
    int ans1 = bfs(2); // left or right
    if (ans0 < 0 && ans1 < 0) std::cout << -1 << std::endl;
    else if (ans0 > 0 && ans1 > 0) std::cout << std::min(ans0, ans1) << std::endl;
    else std::cout << std::max(ans0, ans1) << std::endl;

    return 0;
}
