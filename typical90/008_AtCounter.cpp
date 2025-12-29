#include <iostream>
#include <vector>
#include <string>

std::string S;
static const long long mod = 1e9 + 7;

// void debugger(const std::vector<std::vector<long long>> &dp, int N, int M) {
//     std::cerr << "dp table:\n";
//     for (int i = 0; i <= N; i++) {
//         for (int j = 0; j <= M; j++) {
//             std::cerr << dp[i][j] << " ";
//         }
//         std::cerr << "\n";
//     }
// }

int main() {
    int N;
    std::cin >> N;
    std::cin >> S;
    std::string T = "atcoder";
    int M = (int)T.size();

    std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(M +1, 0));

    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i + 1][j] += dp[i][j];
            if (S[i] == T[j]) dp[i + 1][j + 1] += dp[i][j];
        }
        for (int j = 0; j <= M; j++) dp[i + 1][j] %= mod;
    }

    std::cout << dp[N][M] << std::endl;
    // debugger(dp, N, M);

    return 0;
}

