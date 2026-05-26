#include <bits/stdc++.h>

using P = std::pair<int, int>;

int H, W;

static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};

bool isBound(int i, int j) {
    return (0 <= i && i < H && 0 <= j && j < W);
}

int main() {
    std::cin >> H >> W;

    std::vector<std::vector<char>> A(H, std::vector<char>(W));
    std::vector<std::vector<int>> cnt(H, std::vector<int>(W, 0));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> A[i][j];
            if (A[i][j] != '#') continue;
            for (int d = 0; d < 4; d++) { // init
                int ni = i + di[d];
                int nj = j + dj[d];
                if (!isBound(ni, nj)) continue;
                cnt[ni][nj]++;
            }
        }
    }

    std::queue<P> q;
    for (int i = 0; i < H; i++) { // init
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '.' && cnt[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        int n = q.size();

        std::vector<P> add;
        for (int t = 0; t < n; t++) { // current round only
            auto [i, j] = q.front();
            q.pop();

            if (A[i][j] == '#') continue;
            if (cnt[i][j] != 1) continue;
            add.push_back({i, j});
        }

        for (auto [i, j] : add) { // simultaneous update
            A[i][j] = '#';
        }

        for (auto [i, j] : add) { // propagate
            for (int d = 0; d < 4; d++) {
                int ni = i + di[d];
                int nj = j + dj[d];
                if (!isBound(ni, nj)) continue;

                cnt[ni][nj]++;
                if (A[ni][nj] == '.' && cnt[ni][nj] == 1) {
                    q.push({ni, nj});
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') ans++;
        }
    }
    std::cout << ans << '\n';

    return 0;
}
