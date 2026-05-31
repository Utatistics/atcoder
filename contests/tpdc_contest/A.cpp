#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int M = 0;
    std::vector<int> P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
        M += P[i];
    }

    std::vector<std::vector<bool>> dp(N + 1, std::vector<bool>(M + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (j - P[i] < 0)
                dp[i + 1][j] = dp[i][j];
            else
                dp[i + 1][j] = dp[i][j - P[i]] || dp[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i <= M; i++) {
        if (dp[N][i]) ans++;
    }

    std::cout << ans << std::endl;
    return 0;
}
