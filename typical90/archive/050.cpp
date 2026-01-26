#include <bits/stdc++.h>

using ll = long long;
static const ll MOD = 1e9 + 7;

int main () {
    // input processing
    int N, L;
    std::cin >> N >> L;

    // solve
    std::vector<std::vector<ll>> dp(N + 1, std::vector<ll>(3, 0)); // 0, 1, 2(i.e. L)
    dp[0][0] = 1; // init
    for (int i = 1; i <= N; i++) {
        if (i <= L) {
            dp[i][1] = (i > 1) ? dp[i - 1][1] % MOD : dp[0][0]; // init for i = 1
            dp[i][2] = (i != L) ? 0 : dp[0][0]; // init for i = L
        }

        else {
            dp[i][1] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
            dp[i][2] = (dp[i - L][1] + dp[i - L][2]) % MOD;
        }
    }

    // presentation
    ll ans = dp[N][1] + dp[N][2];
    std::cout << ans << std::endl;
        
    return 0;
}

