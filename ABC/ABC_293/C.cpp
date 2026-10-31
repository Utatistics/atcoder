
#include <bits/stdc++.h>

int H, W;

// down, right
static const int di[2] = {1, 0};
static const int dj[2] = {0, 1};

bool isBound(int i, int j) { return (0 <= i && i < H && 0 <= j && j < W); }

int main() {
    std::cin >> H >> W;

    std::vector<std::vector<int>> G(H, std::vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> G[i][j];
        }
    }

    int ans = 0;

    std::set<int> s;
    auto dfs = [&](auto&& f, int i, int j) -> void {
        if (s.count(G[i][j])) { // duplicates detected
            return;
        }

        s.insert(G[i][j]);
        if (i == H - 1 && j == W - 1) {
            ++ans;
        } 
        else {
            for (int k = 0; k < 2; k++) {
                int ni = i + di[k]; int nj = j + dj[k];
                if (!isBound(ni, nj)) continue;
                f(f, ni, nj);
            }
        }

        s.erase(G[i][j]);
    };
    dfs(dfs, 0, 0);

    std::cout << ans << '\n';

    return 0;
}

