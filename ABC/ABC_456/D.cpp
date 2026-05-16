#include <bits/stdc++.h>

using ll = long long;

static const int MOD = 998244353;

int main() {
    std::string S;
    std::cin >> S;

    int N = S.size();

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(3, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            char c  = 'a' + j;
            if (S[i - 1] ==  c) {
                dp[i][j] = (dp[i][j] + dp[i - 1][0]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][1]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][2]) % MOD;
                dp[i][j]++;
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }

    ll ans = 0;
    for (int x : dp[N]) ans = (ans + x) % MOD;
    std::cout << ans << std::endl;

    return 0;
}

