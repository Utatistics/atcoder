#include <bits/stdc++.h>

using P = std::pair<int, int>;

int H, W;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

int main() {
    std::cin >> H >> W;

    std::vector<std::vector<char>> G(H, std::vector<char>(W));
    std::vector<P> s;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> G[i][j];
            if (G[i][j] == '#') s.emplace_back(i, j);
        }
    }

    for (int i = 0; i < (int)s.size(); i++) {
        auto [r, c] = s[i];
        for (int k = 0; k < 4; k++) {
            int nr = r + di[k];
            int nc = c + dj[k];
            if (!isBound(nr, nc)) continue;
            G[nr][nc] = '*';
        }
    }

    std::vector<std::vector<bool>> visited(H, std::vector<bool>(W, false)); // connected components
    auto bfs = [&](int si, int sj) -> int {
        if (visited[si][sj]) return -1;
        if (G[si][sj] == '#') return -1;
        if (G[si][sj] == '*') return 1;

        int cnt = 1;

        std::queue<P> q;
        q.push({si, sj});
        visited[si][sj] = true;
        
        std::set<P> d;
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();

            for (int k = 0; k < 4; k++) { // define adj list
                int ni = i + di[k]; int nj = j + dj[k];
                if (!isBound(ni, nj)) continue;
                if (G[ni][nj] == '#') continue;
                if (G[ni][nj] == '*') {
                    if (d.count({ni, nj}) > 0) continue;
                    ++cnt; // do not push here
                    d.insert({ni, nj});
                }
                else {
                    if (visited[ni][nj]) continue;
                    ++cnt;
                    q.push({ni, nj});
                }
                visited[ni][nj] = true;
            }           
        }

        return cnt;
    };
    
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int cnt = bfs(i, j);
            ans = std::max(ans, cnt);
        }
    }
    
    std::cout << ans << std::endl;
    return 0;
}

