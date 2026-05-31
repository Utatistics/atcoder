#include <bits/stdc++.h>

int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<int> v(N), w(N);
    for (int i = 0; i < N; i++) {
        std::cin >> v[i] >> w[i];
    }

    std::vector<std::vector<int>> dp(N + 1,std::vector<int>(W + 1, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) // cannot be added
                dp[i + 1][j] = dp[i][j];
            else // can be added
                dp[i + 1][j] = std::max(dp[i][j], dp[i][j - w[i]] + v[i]);
        }
    }

    std::cout << dp[N][W] << '\n';
    return 0;
}
