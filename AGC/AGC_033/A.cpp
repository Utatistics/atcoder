#include <bits/stdc++.h>

struct C {int i; int j; int d; };

int H, W;
std::vector<std::vector<char>> A;
std::queue<C> q;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

int bfs () {
    int ans = 0;

    while (!q.empty()) {
        auto [i, j, d] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) { // grid search
            int id = i + di[k];
            int jd = j + dj[k];

            if (!isBound(id, jd) || A[id][jd] == '#') {
                continue;
            }
            else {
                if (A[id][jd] == '.') A[id][jd] = '#';
                q.push({id, jd, d + 1});
                ans = std::max(ans, d + 1);
            }
        }
    }

    return ans;
}

int main() {
    // input
    std::cin >> H >> W;

    A.resize(H, std::vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> A[i][j];
            if (A[i][j] == '#') q.push({i, j, 0}); // init
        }
    }

    // solve
    int ans = bfs();

    // presentation
    std::cout << ans << std::endl;
    return 0;
}
    
