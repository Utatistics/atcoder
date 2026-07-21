#include <bits/stdc++.h>

using P = std::pair<int, int>;

int H, W;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

static const int INF = 1e9;

int main() {
    std::cin >> H >> W;

    std::vector<std::string> G(H);
    for (int i = 0; i < H; i++) {
        std::cin >> G[i];
    }
    int si, sj, ti, tj;
    std::cin >> si >> sj >> ti >> tj;
    --si; --sj; --ti; --tj;

    std::vector<std::vector<int>> dist(H, std::vector<int>(W, INF));
    std::vector<std::vector<bool>> visited(H, std::vector<bool>(W, false));
    std::deque<P> dq;

    auto push = [&](int i, int j, int d, int c) {
        if (dist[i][j] <= d) return;
        dist[i][j] = d;
        if (c == 0) dq.push_front({i, j});
        else dq.push_back({i, j});
    };

    push(si, sj, 0, 0); // init
    while (!dq.empty()) {
        auto [i, j] = dq.front(); dq.pop_front();
        if (visited[i][j]) continue;
        visited[i][j] = true;

        int d = dist[i][j];
        for (int v = 0; v < 4; v++) {
            int ni = i + di[v], nj = j + dj[v];
            if (!isBound(ni, nj)) continue;
            if (G[ni][nj] == '.') push(ni, nj, d, 0);
        }
        for (int v = 0; v < 4; v++) { // break wall
            int ni = i, nj = j;
            for (int k = 0; k < 2; k++) {
                ni += di[v]; nj += dj[v];
                if (!isBound(ni, nj)) break; // not continue?
                push(ni, nj, d+1, 1);
            }
        }
    }

    int ans = dist[ti][tj];
    std::cout << ans << std::endl;

    return 0;
}

