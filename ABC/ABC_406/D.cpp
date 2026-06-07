#include <bits/stdc++.h>

int main() {
    int H, W, N;
    std::cin >> H >> W >> N;

    std::vector<std::vector<int>> G(H, std::vector<int>(W, 0));
    for (int i = 0; i < N; i++) {
        int r, c;
        std::cin >> r >> c;
        r--; c--;
        G[r][c]++;
    }

    std::vector<std::vector<int>> imos(H + 1, std::vector<int>(W + 1, 0));
    for (int i = 0; i < H; i++) {
        for (int i = 0; i < W; i++) {
            
        }
    }

    int Q;
    std::cin >> Q;
    
    while (Q--) {
        int t;
        std::cin >> t;
        int x;
        std::cin >> x;
        x--;
        
        if (t == 1) {

        }
        else {

        }
    }
    return 0;
}

