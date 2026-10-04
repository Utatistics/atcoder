#include <bits/stdc++.h>

using ll = long long;
static const int INF = 1e9;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
        std::cin >> Y[i];
    }

    std::vector<std::vector<ll>> dp(N + 1, std::vector<ll>(2, -INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        dp[i + 1][0] = dp[i][0];
        dp[i + 1][1] = dp[i][1];
        
        if (X[i] == 0) {
            dp[i + 1][0] = std::max(dp[i + 1][0], dp[i][0] + Y[i]);
            dp[i + 1][0] = std::max(dp[i + 1][0], dp[i][1] + Y[i]);
        }
        else {
            dp[i + 1][1] = std::max(dp[i + 1][1], dp[i][0] + Y[i]);
        }
    }

    std::cout << std::max(dp[N][0], dp[N][1]) << std::endl;
    return 0;
}

