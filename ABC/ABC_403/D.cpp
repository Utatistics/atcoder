#include <bits/stdc++.h>

static constexpr int MAX = 1000000;

int f(const std::vector<int>& A) {
    int S = A.size();
    std::vector<std::vector<int>> dp(S + 1, std::vector<int>(2, 0));

    for (int i = 0; i < S; i++) {
        dp[i + 1][0] = A[i] + std::min(dp[i][0], dp[i][1]); // delete
        dp[i + 1][1] = dp[i][0]; // keep
    }

    return std::min(dp[S][0], dp[S][1]);
}

int main() {
    int N, D;
    std::cin >> N >> D;

    std::vector<int> cnt(MAX + 1, 0);
    int M = 0; // max
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        cnt[a]++;
        M = std::max(M, a);
    }

    if (D == 0) { // edge case
        int ans = 0;
        for (int i = 0; i <= M; i++) {
            if (cnt[i] > 0) ans += cnt[i] - 1;
        }
        std::cout << ans << '\n';
        return 0;
    }

    int ans = 0;
    for (int r = 0; r < D; r++) {
        std::vector<int> A;
        for (int x = r; x <= M; x += D) {
            A.push_back(cnt[x]);
        }
        ans += f(A);
    }

    std::cout << ans << '\n';

    return 0;
}
