#include <bits/stdc++.h>

int N, M;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};

int main() {
    std::cin >> N >> M;

    std::vector<std::string> G(N);
    for (int i = 0; i < N; i++) std::cin >> G[i];
    

    std::vector<std::vector<std::array<bool,4>>> v(N, std::vector<std::array<bool, 4>>(M));
    std::vector<std::vector<bool>> lv(N, std::vector<bool>(M, false)); // local visited

    auto dfs = [&](auto&&f, int i, int j, int d) -> void {
        if (v[i][j][d]) {
            return;
        }

        v[i][j][d] = true;
        lv[i][j] = true;

        int ni = i + di[d];
        int nj = j + dj[d];

        if (G[ni][nj] == '#') { // stops at (i, j)
            for (int dir = 0; dir < 4; dir++) { // choose any direction 
                f(f, i, j, dir);
            }
        }
        else { // Continue sliding in the same direction.
            f(f, ni, nj, d);
        }
    };

    for (int d = 0; d < 4; d++) {
        dfs(dfs, 1, 1, d);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (lv[i][j]) {
                ans++;
            }
        }
    }
    std::cout << ans << '\n';

    return 0;
}
