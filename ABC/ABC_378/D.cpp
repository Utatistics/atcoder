#include <bits/stdc++.h>

int H, W, K;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};

bool isBound(int i, int j) {
    return (0 <= i && i < H && 0 <= j && j < W);
}

int main() {
    std::cin >> H >> W >> K;

    std::vector<std::vector<char>> G(H, std::vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> G[i][j];
        }
    }

    int ans = 0;
    std::vector<std::vector<bool>> visited(H, std::vector<bool>(W, false));

    auto dfs = [&](auto& self, int i, int j, int d) -> void {
        visited[i][j] = true;

        if (d == K) {
            ++ans;
            visited[i][j] = false;
            return;
        }

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (!isBound(ni, nj)) continue;
            if (G[ni][nj] == '#') continue;
            if (visited[ni][nj]) continue;

            self(self, ni, nj, d + 1);
        }

        visited[i][j] = false;
        return; // no necessary, but b explicit
    };

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (G[i][j] == '.') {
                dfs(dfs, i, j, 0);
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
