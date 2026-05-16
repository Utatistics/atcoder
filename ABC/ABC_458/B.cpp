#include <bits/stdc++.h>

int H, W;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

int main() {
    std::cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int ans = 4;
            for (int k = 0; k < 4; k++) {
                if(!isBound(i + di[k], j + dj[k])) ans--;
            }
            std::cout << ans << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
