#include <bits/stdc++.h>

static const int INF = 1e9;
using T = std::tuple<int, int, int>; // i, j, dir


int H, W;
int rs, cs, rt, ct;
std::vector<std::vector<char>> S;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0}; 
static const int dj[4] = {0, 0, -1, 1};

std::vector<std::vector<std::vector<int>>> dist; // d[i][j][dir] (i.e. coming to i, j from dir)

void bfs(int rs, int cs) {
    std::deque<T> dq;

    for (int d = 0; d < 4; d++) { // init
        dist[rs][cs][d] = 0;
        dq.emplace_front(rs, cs, d);
    }

    while (!dq.empty()) {
        auto [i0, j0, d0] = dq.front(); dq.pop_front(); // dir = previous direction
        for (int d1 = 0; d1 < 4; d1++) { // next (4 ways
            int i1 = i0 + di[d1];
            int j1 = j0 + dj[d1];

            if (i1 < 0 || H <= i1 || j1 < 0 || W <= j1) continue; // out of bounds
            if (S[i1][j1] == '#') continue; // dead end

            int c = (d0 == d1) ? 0 : 1; // cost (i.e. 0-1 BFS)

            if (dist[i1][j1][d1] > dist[i0][j0][d0] + c) { // update if 
                dist[i1][j1][d1] = dist[i0][j0][d0] + c;

                if (c == 0) dq.emplace_front(i1, j1, d1);
                else dq.emplace_back(i1, j1, d1);
            }
        }
    }
}

int main() {
    // inputi
    std::cin >> H >> W;
    std::cin >> rs >> cs >> rt >> ct;
    rs--; cs--; rt--; ct--;

    S.assign(H, std::vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> S[i][j];
        }
    }

    dist.assign(H, std::vector<std::vector<int>>(W, std::vector<int>(4, INF)));

    // solve
    bfs(rs, cs);

    // take min over 4 directions
    int ans = INF;
    for (int dir = 0; dir < 4; dir++) {
        ans = std::min(ans, dist[rt][ct][dir]);
    }

    std::cout << ans << std::endl;

    return 0;
}

