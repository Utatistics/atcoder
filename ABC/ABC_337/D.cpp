#include <bits/stdc++.h>

static constexpr int INF = 1e9;

int main() {
    int H, W, K;
    std::cin >> H >> W >> K;

    std::vector<std::string> G(H);
    for (int i = 0; i < H; i++) std::cin >> G[i];

    int ans = INF;
    for (int i = 0; i < H; i++) {
        int x = 0, d = 0;
        for (int j = 0; j < W; j++) {

            if (G[i][j] == '.') ++d;
            if (G[i][j] == 'x') ++x;

            if (j >= K) {
                if (G[i][j - K] == '.') --d;
                if (G[i][j - K] == 'x') --x;
            }

            if (j + 1 >= K && x == 0) {
                ans = std::min(ans, d);
            }
        }
    }
    for (int j = 0; j < W; j++) {
        int x = 0, d = 0;
        for (int i = 0; i < H; i++) {

            if (G[i][j] == '.') ++d;
            if (G[i][j] == 'x') ++x;

            if (i >= K) {
                if (G[i - K][j] == '.') --d;
                if (G[i - K][j] == 'x') --x;
            }

            if (i + 1 >= K && x == 0) {
                ans = std::min(ans, d);
            }
        }
    }

    if (ans == INF) ans = -1;
    std::cout << ans << std::endl;
    return 0;
}

