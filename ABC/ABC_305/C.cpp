#include <bits/stdc++.h>

int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<char>> G(H, std::vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> G[i][j];
        }
    }

    int a = W; int b = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (G[i][j] == '#') {
                a = std::min(a, j);
                b = std::max(b, j);
            }
        }
    }
    int c = H; int d = -1;
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H; i++) {
            if (G[i][j] == '#') {
                c = std::min(c, i);
                d = std::max(d, i);
            }
        }
    }

    for (int i = c; i <= d; i++) {
        for (int j = a; j <= b; j++) {
            if (G[i][j] != '#') {
                std::cout << i + 1 << " " << j + 1 << std::endl;
                break;
            }
        }
    }

    return 0;
}

