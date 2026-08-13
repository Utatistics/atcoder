#include <bits/stdc++.h>

int H, W;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

int main() {
    int N;
    std::cin >> H >> W >> N;
    
    std::string T;
    std::cin >> T;

    std::vector<std::string> G(H);
    for (int i = 0; i < H; i++) std::cin >> G[i];
    
    auto dir = [&](char c) -> int {
        if (c == 'U') return 0;
        else if (c == 'D') return 1;
        else if (c == 'L') return 2;
        else return 3; // 'R'
    };

    auto search = [&](int si, int sj) -> bool {
        int cnt = 0;
        int i = si, j = sj;
        for (int k = 0; k < N; k++) {
            int d = dir(T[k]);
            int ni = i + di[d], nj = j + dj[d];
            if (G[ni][nj] == '#') continue;
            
            ++cnt;
            i = ni; j = nj;
        }
        return cnt == N;
    };

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (G[i][j] == '#') continue;
            if(search(i, j)) ++ans;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
