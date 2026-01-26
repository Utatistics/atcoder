#include <bits/stdc++.h>

using ll = long long;
static const ll MOD = 1e9 + 7;

int main () {
    int N, L;
    std::cin >> N >> L;

    std::vector<std::vector<ll>> dp(N + 1, std::vector<ll>(3, 0)); 
    dp[0][1] = 1; // starting at step 0, last move "1-step" (dummy)
    dp[0][2] = 0; // can't start with L-step

    for (int i = 1; i <= N; i++) {
        dp[i][1] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
        if (i >= L)
            dp[i][2] = (dp[i - L][1] + dp[i - L][2]) % MOD;
    }

    ll ans = (dp[N][1] + dp[N][2]) % MOD;
    std::cout << ans << "\n";

    return 0;
}

