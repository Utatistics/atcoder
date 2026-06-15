#include <bits/stdc++.h>

using P = std::pair<int, int>;

int H, W;
// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
static const char d[4] = {'v', '^', '>', '<'}; // flipped

bool isBound(int i, int j) { return (0 <= i && i < H && 0 <= j && j < W);}


int main() {
    std::cin >> H >> W;

    std::vector<std::string> S(H);
    for (int i = 0; i < H; i++) std::cin >> S[i];

    std::vector<std::vector<int>> dist(H, std::vector<int>(W, -1));
    std::vector<std::vector<char>> dir(H, std::vector<char>(W, '.'));
    
    std::queue<P> q;
    for (int i = 0; i < H; i++) { // init
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'E') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        P x = q.front(); q.pop();
        int i = x.first;
        int j = x.second;

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (!isBound(ni, nj)) continue;
            if (S[ni][nj] == '#') continue;
            if (dist[ni][nj] < 0) {
                dist[ni][nj] = dist[i][j] + 1;
                dir[ni][nj] = d[k];

                q.push({ni, nj});
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (dir[i][j] == '.') std::cout << S[i][j];
            else std::cout << dir[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}

