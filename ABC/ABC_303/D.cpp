#include <bits/stdc++.h>

using ll = long long;
static const ll INF = 1e18;

int main() {
    int X, Y, Z;
    std::cin >> X >> Y >> Z;

    std::string S;
    std::cin >> S;
    int N = (int)S.size();

    std::vector<std::array<ll, 2>> dp(N + 1, std::array<ll, 2>{INF, INF});

    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') {
            dp[i + 1][0] = std::min(dp[i][0] + Y, dp[i][1] + Z + Y);
            dp[i + 1][1] = std::min(dp[i][1] + X, dp[i][0] + Z + X);
        } 
        else {
            dp[i + 1][0] = std::min(dp[i][0] + X, dp[i][1] + Z + X);
            dp[i + 1][1] = std::min(dp[i][1] + Y, dp[i][0] + Z + Y);
        }
    }

    std::cout << std::min(dp[N][0], dp[N][1]) << '\n';
}
