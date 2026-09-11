#include <bits/stdc++.h>

using ll = long long;
static const ll INF = 1LL << 60;

int main() {
    int N;
    std::cin >> N;

    int M = 0;
    std::vector<int> x(N), y(N), z(N);
    for (int i = 0; i < N; i++) {
        std::cin >> x[i] >> y[i] >> z[i];
        M += z[i];
    }

    std::vector<std::vector<ll>> dp(N + 1, std::vector<ll>(M + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        ll c = std::max(0, (y[i] - x[i] + 1) / 2);
        for (int j = 0; j <= M; j++) {
            if (dp[i][j] == INF) continue;
            dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);

            if (j + z[i] > M) continue;
            dp[i + 1][j + z[i]] = std::min(dp[i + 1][j + z[i]], dp[i][j] + c);
        }
    }

    ll ans = INF;
    for (int j = M / 2 + 1; j <= M; j++) {
        ans = std::min(ans, dp[N][j]);
    }

    std::cout << ans << '\n';
}
