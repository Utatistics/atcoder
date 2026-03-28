#include <bits/stdc++.h>

int H, W;
std::vector<std::vector<char>> S;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}
bool ans;
std::vector<std::vector<bool>> visited;

void dfs(int i, int j) {
    if (visited[i][j]) return;
    visited[i][j] = true; // visited

    for (int k = 0; k < 4; k++) { // grid search
        int id = i + di[k];
        int jd = j + dj[k];

        if (!isBound(id, jd)) continue;
        else if (S[id][jd] == '#') continue;
        else if (S[id][jd] == 'g') ans = true;
        else dfs(id, jd);
        }
}

int main() {
    // input
    std::cin >> H >> W;
    S.resize(H, std::vector<char>(W));
    visited.resize(H, std::vector<bool>(W, false));
    
    ans = false;

    int rs = -1;
    int cs = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> S[i][j];
            if (S[i][j] == 's') { 
                rs = i; cs = j;
            }
        }
    }

    // solve
    dfs(rs, cs);
    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

