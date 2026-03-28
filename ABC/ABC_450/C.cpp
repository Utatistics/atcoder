#include <bits/stdc++.h>

using P = std::pair<int, int>;

// input
int H, W;
std::vector<std::string> S;

// up, down, left, righti
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
std::vector<std::vector<bool>> visited;
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

int bfs(int si, int sj) {
    int cnt = 0; // bound cconter
    std::queue<P> q;

    visited[si][sj] = true;
    q.push(std::make_pair(si, sj));
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) { // grid search
            int id = i + di[k];
            int jd = j + dj[k];
            if (!isBound(id, jd)) {
                cnt++; // invalid already
                continue; // yet visit the rest
            }
            if (S[id][jd] == '#') continue;
            if (visited[id][jd] == false) {
                visited[id][jd] = true;
                q.push(std::make_pair(id, jd));
            }
        }
    }

    return cnt;
}

int main() {
    // input
    std::cin >> H >> W;
    visited.resize(H, std::vector<bool>(W, false));

    S.resize(H);
    for (int i = 0; i < H; i++) std::cin >> S[i];
     
    // solve
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (visited[i][j] || S[i][j] == '#') continue;
            int c = bfs(i , j);
            if (c == 0) ans++;
        }
    }

    // presentaiton
    std::cout << ans << std::endl;
    return 0;
}

