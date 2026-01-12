#include <iostream>
#include <vector>
#include <algorithm>

static const int MOD = 1e9 + 7;

// void debugger(const std::vector<int> &dp) {
//     for (int i = 0; i < (int)dp.size(); i++) std::cout << dp[i] << " ";
//     std::cout << std::endl;
// }

int main () {
    int K;
    std::cin >> K;

    if (K % 9 != 0) std::cout << 0;
    else {
        std::vector<int> dp(K + 1, 0);
        dp[0] = 1; // init
        for (int i = 1; i <= K; i++) { // 'i' as digit sum
            int d = std::min(i, 9); // the last digit <= 9, <= i
            for (int j = 1; j <= d; j++) { // 'j' as last digit
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
        // debugger(dp);
        std::cout << dp[K] % MOD << std::endl;
    }

    return 0;
}
// e.g.
// i=4   
// j=1 -> dp[3] 31 121 211 1111
// j=2 -> dp[2] 112 22
// j=3 -> dp[1] 13
// j=4 -> dp[0] 4
