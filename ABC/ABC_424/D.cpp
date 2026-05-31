#include <bits/stdc++.h>

static const int di[4] = {0, 0, 1, 1};
static const int dj[4] = {0, 1, 0, 1};

int main() {
    int T;
    std::cin >> T;
    
    while (T--) {
        int H, W;
        std::cin >> H >> W;

        std::vector<std::string> S(H);
        for (int i = 0; i < H; i++) std::cin >> S[i];

        int ans = 9;
        
        auto f = [&](auto f, int d) -> void {
            if (d >= ans) return;

            for (int i = 0; i < H - 1; i++) { // O(H * W)
                for (int j = 0; j < W - 1; j++) {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) 
                        if (S[i + di[k]][j + dj[k]] == '#') cnt++;
                    if (cnt != 4) continue;
                    
                    // found a 'bad' 2 * 2
                    for (int k = 0; k < 4; k++) { // recursion
                        S[i + di[k]][j + dj[k]] = '.'; // rewrite
                        f(f, d + 1);
                        S[i + di[k]][j + dj[k]] = '#';  // revert
                    }
                    return;
                }
            }
            ans = std::min(ans, d);
        };

        f(f, 0);
        std::cout << ans << std::endl;
    }

    return 0;
}

