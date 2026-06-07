#include <bits/stdc++.h>

using ll = long long;

int main() {
    int H, W, K;
    std::cin >> H >> W >> K;

    std::vector<std::vector<int>> S(H, std::vector<int>(W));
    for (int i = 0; i < H; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < W; j++) {
            S[i][j] = s[j] - '0';
        }
    }

    std::vector<std::vector<int>> pref(H + 1, std::vector<int>(W + 1, 0));
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
           pref[i][j] = pref[i][j - 1] + S[i - 1][j - 1];
        }
    }  
    for (int j = 1; j <= W; j++) {
        for (int i = 1; i <= H; i++) {
           pref[i][j] += pref[i - 1][j];
        }
    }  

    auto binarySearch = [&](int u, auto solve, int k) -> int {
        int up = u - 1; // - 1
        int down = H + 1; // size of pref
        while (down - up > 1) {
            int mid = up + (down - up) / 2;
            if (solve(mid) >= k) down = mid;
            else up = mid;
        }
        return down;
    };

    ll ans = 0;
    for (int l = 1; l <= W; l++) {
        for (int r = l; r <= W; r++) {
            for (int u = 1; u <= H; u++) {

                auto f = [&](int d) -> int { // 2d sum given d
                    return pref[d][r]
                         - pref[u - 1][r] // u - 1 has 0 buffer
                         - pref[d][l - 1] // l - 1 has 0 buffer
                         + pref[u - 1][l - 1];
                };

                int d0 = binarySearch(u, f, K);
                if (d0 == H + 1) continue; // d not found
                if (f(d0) != K) continue; // excact match required 
                int d1 = binarySearch(u, f, K + 1);

                ans += d1 - d0;
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}

