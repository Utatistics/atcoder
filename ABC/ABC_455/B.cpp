#include <bits/stdc++.h>

int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<char>> S(H, std::vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> S[i][j];
        }
    }

    int ans = 0;
    for (int h1 = 0; h1 < H; h1++) {
        for (int h2 = h1; h2 < H; h2++) {
            for (int w1 = 0; w1 < W; w1++) {
                for (int w2 = w1; w2 < W; w2++) {
                    
                    bool status = true;
                    for (int i = h1; i <= h2; i++) {
                        for (int j = w1; j <= w2; j++) {
                            if (S[i][j] != S[h1 + h2 - i][w1 + w2 - j]) {
                                status = false;
                                break;
                            }
                        }
                        if(!status) break;
                    }
                    if(status) ans++;
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

