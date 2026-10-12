#include <bits/stdc++.h>

int H, W;

// up, down, left, right
static const int di[4] = {-1, 1, 1, -1};
static const int dj[4] = {1, 1, -1, -1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

int main() {
    std::cin >> H >> W;

    std::vector<std::string> C(H);
    for (int i = 0; i < H; i++) std::cin >> C[i]; 
    
    int N = std::min(H, W);
    std::vector<int> cnt(N, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            bool flg = true;

            if (C[i][j] != '#') {
                flg = false;
                continue;
            }    
            for (int k = 0; k < 4; k++) {
                int ni = i + di[k]; int nj = j + dj[k];
                if (!isBound(ni, nj) || C[ni][nj] != '#') flg = false;
            }
            if (!flg) continue;
            
            int s = -1; // center does not count
            int ni = i, nj = j;
            while (isBound(ni, nj) && C[ni][nj] == '#') { // size search
                ++s;
                ni += di[0];
                nj += dj[0];
            }
            cnt[s - 1]++; // 0 origin
        }
    }
    for (int i = 0; i < N; i++) std::cout << cnt[i] << " ";
    std::cout << std::endl;

    return 0;
}

