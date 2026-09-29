#include <bits/stdc++.h>

static const int INF = 3001;
static const int MOD = 998244353;

int main() {
    std::string S;
    std::cin >> S;

    int N = (int)S.size();

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(INF, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < INF; j++) {
            if (S[i] != ')' && j < INF) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;

            }
            if (S[i] != '(' && j > 0) {
                dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
            }
        }
    }

    std::cout << dp[N][0] << std::endl;
    return 0;
}

