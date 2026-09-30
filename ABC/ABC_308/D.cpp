#include <bits/stdc++.h>

using P = std::pair<int, int>;

int H, W;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

int main() {
    std::cin >> H >> W;

    std::vector<std::string> G(H);
    for (int i = 0; i < H; i++) {
        std::cin >> G[i];
    }
    if (G[0][0] != 's') {
        std::cout << "No\n";
        return 0;
    }

    std::map<char , char> m = {
        {'s', 'n'},
        {'n', 'u'},
        {'u', 'k'},
        {'k', 'e'},
        {'e', 's'}
    };

    auto bfs = [&]() -> bool {
        std::queue<P> q;
        std::vector<std::vector<bool>> visited(H, std::vector<bool>(W, false));

        q.emplace(0, 0);
        visited[0][0] = true;

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();

            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (!isBound(ni, nj)) continue;
                if (m.count(G[i][j]) == 0) continue;
                if (G[ni][nj] != m[G[i][j]]) continue;
                if (ni == H - 1 && nj == W - 1) {
                    return true;
                }
                if (visited[ni][nj]) continue;
                visited[ni][nj] = true;

                q.emplace(ni, nj);
            }
        }

        return false;
    };
    auto ans = bfs();
    
    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}
