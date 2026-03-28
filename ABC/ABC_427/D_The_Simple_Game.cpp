#include <iostream>
#include <vector>
#include <unordered_set>

bool dpSolve(std::vector<bool> &dp, const std::vector<std::vector<int>> &adj, int k, int N) {
    std::vector<bool> x(dp.begin() + k*N, dp.begin() + k*N + N); // slice row k
    std::unordered_set<int> s;
    for (int i = 0; i < N; i++)
        if (!x[i]) s.insert(i);

    for (const auto& neighbors : adj)
        for (int node : neighbors)
            if (s.count(node)) return true;
    return false;
}

int main () {
    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        int N, M, K;
        std::cin >> N >> M >> K;
        std::string S;
        std::cin >> S;
        
        // Store Graph
        std::vector<std::vector<int>> adj(N);
        for (int i = 0; i < M; i++) {
            int u, v;
            std::cin >> u >> v;
            adj[--u].push_back(--v);
        }

        // dynamic programming: Game Theory
        std::vector<bool> dp(2 * K * N, false); // 2d array
        for (int k = 2 * K - 1; k >= 0; k--) {
            for (int v = 0; v < N; v++) {
                if ( k == 2 * K - 1 ) {
                    dp[k + v] = (S[v] == 'A');
                } else {
                    dp[k * (2 * K - 1 + v)] = dpSolve(dp, adj, k, N);
                }
            }
        }
        // find the winner
        for (int i = 0; i < 2 * K * N; i++) {
            if (dp[i]) {
               int winner = i / (2 * K);
               if (winner % 2 == 0) std::cout << "Alice" << std::endl;
               else std::cout << "Bob" << std::endl;
            };
            break;
        }
    }
}
