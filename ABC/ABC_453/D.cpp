#include <bits/stdc++.h>

using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int H, W;
P s, g;
std::vector<std::vector<char>> S;
std::vector<std::vector<std::vector<int>>> path;
std::string ans;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};

bool isBound(int i, int j) { return (0 <= i && i < H && 0 <= j && j < W);}

void bfs() {
    std::queue<T> q;

    for (int nd = 0; nd < 4; nd++) {
        path[s.first][s.second][nd] = 1e9; // start marker
        q.push({s.first, s.second, nd});
    }

    while (!q.empty()) {
        auto [i, j, d] = q.front();q.pop();
        if (i == g.first && j == g.second) { // path reconstruction
            std::cout << "Yes" << std::endl;

            ans = "";
            while (path[i][j][d] != 1e9) {
                ans += "UDLR"[d];
                int pd = path[i][j][d];
                i -= di[d]; j -= dj[d]; d = pd;
            }
            std::reverse(ans.begin(), ans.end());
            return;
        }

        for (int nd = 0; nd < 4; nd++) {
            int ni = i + di[nd];
            int nj = j + dj[nd];

            if (S[i][j] == 'o' && d != nd) continue;
            if (S[i][j] == 'x' && d == nd) continue;
            if (!isBound(ni, nj)) continue;
            if (path[ni][nj][nd] != -1) continue;
            if (S[ni][nj] == '#') continue;

            q.push({ni, nj, nd}); // took 'nd' to get {ni, nj}
            path[ni][nj][nd] = d;
        }
    }
}

int main() {
    std::cin >> H >> W;

    S.assign(H, std::vector<char>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> S[i][j];
            if (S[i][j] == 'S') s = {i, j};
            if (S[i][j] == 'G') g = {i, j};
        }
    }

    path.assign(H, std::vector<std::vector<int>>(W, std::vector<int>(4, -1)));

    bfs();

    if (!ans.empty()) std::cout << ans << std::endl;
    else std::cout << "No\n";

    return 0;
}
