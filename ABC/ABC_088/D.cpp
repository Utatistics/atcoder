#include <bits/stdc++.h>

using P = std::pair<int, int>;

int H, W;
std::vector<std::vector<char>> S;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

std::vector<std::vector<int>> dist;
std::vector<std::vector<P>> par; // parent
std::set<P> path; // path

void bfs(int si, int sj) {
    std::queue<P> q;

    q.push({si, sj});
    par[si][sj] = {si, sj}; // mark as visited
    dist[si][sj] = 0;

    while (!q.empty()) {
        P x = q.front(); q.pop();
        int i = x.first;
        int j = x.second;

        for (int k = 0; k < 4; k++) {
            int id = i + di[k];
            int jd = j + dj[k];

            if (!isBound(id, jd) || S[id][jd] == '#' || par[id][jd] != P{-1, -1})
                continue;
            else {
                par[id][jd] = {i, j};
                dist[id][jd] = dist[i][j] + 1;
                q.push({id, jd});
            }
        }
    }
}

int main() {
    // input
    std::cin >> H >> W;
    
    S.resize(H, std::vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) std::cin >> S[i][j];
    }

    dist.assign(H, std::vector<int>(W, -1));
    par.assign(H, std::vector<P>(W, P{-1, -1}));

    // solve
    bfs(0, 0);
 
    P p = {H - 1, W - 1};
    if (par[p.first][p.second] == P{-1, -1}) { // unreachable
        std::cout << -1 << std::endl;
        return 0;
    }
    while (true) {
        path.insert(p);
        if (p == par[p.first][p.second]) break; // reached start
        p = par[p.first][p.second];
    }
    
    // presentaiton
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if(S[i][j] == '.' && path.count({i, j}) == 0) ans++;
        }
    }
    std::cout << ans << std::endl;
    
    return 0;
}

