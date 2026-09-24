#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> D(N, std::vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            std::cin >> D[i][j];
            D[j][i] = D[i][j];
        }
    }

    std::vector<ll> dp(1 << N, -1);
    dp[0] = 0;
    for (int b = 0; b < (1 << N) - 1; ++b) { //O(N * 2^N)
        if (dp[b] < 0) continue;
        int l = -1;
        for (int i = 0; i < N; ++i) {
            if (!(b & (1 << i))) { // choose i if not used in b
                l = i;
                break;
            }
        }
        std::cout << "b =" << std::bitset<4>(b) << std::endl;
        
        for (int r = l; r < N; ++r) { // l == r means not paring
            if (b & (1 << r)) { // can't choose if used in b
                continue;
            }
            int nb = b | (1 << l) | (1 << r);
            std::cout << "nb=" << std::bitset<4>(nb) << std::endl;
            dp[nb] = std::max(dp[nb], dp[b] + D[l][r]);
        }
        std::cout << std::endl;
    }

    std::cout << dp[(1 << N) - 1] << '\n';
    return 0;
}

