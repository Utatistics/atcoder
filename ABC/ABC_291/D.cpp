#include <bits/stdc++.h>

static constexpr int MOD = 998244353;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::vector<std::array<int, 2>> dp(N);

    dp[0] = {1, 1};

    for (int i = 1; i < N; i++) {
        if (A[i] != A[i - 1]) {
            dp[i][0] += dp[i - 1][0];
        }
        if (A[i] != B[i - 1]) {
            dp[i][0] += dp[i - 1][1];
        }
        if (B[i] != A[i - 1]) {
            dp[i][1] += dp[i - 1][0];
        }
        if (B[i] != B[i - 1]) {
            dp[i][1] += dp[i - 1][1];
        }

        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }

    std::cout << (dp[N - 1][0] + dp[N - 1][1]) % MOD << '\n';
}
