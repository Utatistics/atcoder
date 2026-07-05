#include <bits/stdc++.h>

static constexpr int INF = 1e9;

int main() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    auto f = [&](int i, int h) -> int {
        switch (S[i]) {
            case 'R':
                if (h == 0) return 0;
                if (h == 1) return 1;
                if (h == 2) return -INF;
                break;
            case 'P':
                if (h == 0) return -INF;
                if (h == 1) return 0;
                if (h == 2) return 1;
                break;
            case 'S':
                if (h == 0) return 1;
                if (h == 1) return -INF;
                if (h == 2) return 0;
                break;
        }
        return -INF; // unreachable
    };

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(3, -INF));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            if (f(i, j) < 0) continue; // no lose

            int s = 0;
            for (int k = 0; k < 3; k++) {
                if (i > 0 && j == k) continue;
                s = std::max(s, dp[i][k]);
            }
            dp[i + 1][j] = s;
            dp[i + 1][j] += std::max(f(i, j), 0); // wins
        }
    }

    int ans = 0;
    for (int i = 0; i < 3; i++) ans = std::max(ans, dp[N][i]);
    std::cout << ans << std::endl;
    return 0;
}

