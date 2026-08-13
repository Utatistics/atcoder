#include <bits/stdc++.h>

static constexpr int INF = 1e9;

int main() {
    std::string T;
    std::cin >> T;

    int N;
    std::cin >> N;
    int M = (int)T.size();

    std::vector<std::vector<std::string>> A(N);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;

        for (int j = 0; j < a; j++) {
            std::string s;
            std::cin >> s;
            A[i].push_back(s);
        }
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]); // no choose

            for (std::string s : A[i]) { // choose 
                int n = (int)s.size();
                if (j + n > M) continue; // will go over 
                if (s == T.substr(j, n)) { // exact match
                    dp[i + 1][j + n] = std::min(dp[i + 1][j + n], dp[i][j] + 1);
                }
            }
        }
    }

    int ans = INF;
    for (int i = 0; i <= N; i++) 
        ans = std::min(ans, dp[i][M]);
    if (ans == INF) ans = -1;
    std::cout << ans << std::endl;

    return 0;
}

