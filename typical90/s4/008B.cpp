#include <iostream>
#include <string>
#include <vector>

static const long long DIV = 1e9 + 7;

// void debugger(std::vector<std::vector<long long>> &dp) {
//     int N = dp.size();
//     int M = dp[0].size();
    
//     std::cerr << "dp:\n";
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < M; j++) {
//             std::cerr << dp[i][j] << " ";
//         }
//         std::cerr << "\n";
//     }
// }

int main () {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;
    std::string T = "atcoder";
    int M = T.size();
    std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(M + 1, 0));

    dp[0][0] = 1; // O(M*N)
    for (int t = 0; t < M; t++) {
        for (int s = 0; s < N; s++) {
            if (dp[s][t]) {
                int k = 1;
                while (k < N - s + 1) {
                    dp[s + k][t + 1] += (S[s + k - 1] == T[t] ? dp[s][t] : 0);
                    k++;
                }
            }
        }
    }
    
    long long ans = 0;
    for (int i = 0; i < N + 1; i++) ans += dp[i][M]; // O(N)
    
    //std::cout << ans << "%" << DIV << "=";
    std::cout << ans % DIV << std::endl;
    //debugger(dp); // debug
    return 0;
}

