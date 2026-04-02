#include <bits/stdc++.h>

using P = std::pair<int, int>;

int H, W;
int si, sj; // init
std::vector<std::vector<char>> C;
std::vector<std::vector<bool>> visited;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);} // is safe

int dfs(int i, int j, int c) {
    if (visited[i][j]) {
        if (i == si && j == sj && c >= 3) return c;
        else return -1;
    }

    visited[i][j] = true;

    int res = -1;

    for (int k = 0; k < 4; k++) {
        int id = i + di[k];
        int jd = j + dj[k];

        if (!isBound(id, jd) || C[id][jd] == '#') continue;

        int cnt = dfs(id, jd, c + 1);
        res = std::max(res, cnt);
    }

    visited[i][j] = false;

    return res;
}

int main() {
    // input
    std::cin >> H >> W;
    C.resize(H, std::vector<char>(W));

    std::vector<P> S;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> C[i][j];
            if (C[i][j] == '.') S.push_back({i, j});
        }
    }

    // solve
    int ans = -1;
    visited.resize(H, std::vector<bool>(W, false));

    for (P p : S) {
        si = p.first; sj = p.second;
        int cnt = dfs(si, sj, 0);
        ans = std::max(ans, cnt);
    }

    // presentation
    std::cout << ans << std::endl;

    return 0;
}

