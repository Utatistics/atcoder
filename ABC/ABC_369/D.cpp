#include <bits/stdc++.h>

static const ll NEG = -(1LL << 60);
using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    std::vector<std::vector<ll>> dp(N + 1, std::vector<ll>(2, NEG));
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        // skip
        dp[i][0] = std::max(dp[i][0], dp[i - 1][0]);
        dp[i][1] = std::max(dp[i][1], dp[i - 1][1]);

        // kill
        if (dp[i - 1][0] != NEG)
            dp[i][1] = std::max(dp[i][1], dp[i - 1][0] + A[i - 1]);

        if (dp[i - 1][1] != NEG)
            dp[i][0] = std::max(dp[i][0], dp[i - 1][1] + 2LL * A[i - 1]);
    }

    std::cout << std::max(dp[N][0], dp[N][1]) << std::endl;

    return 0;
}
