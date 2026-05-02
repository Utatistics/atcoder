#include <bits/stdc++.h>

int main () {
    int T;
    std::cin >> T;

    while (T--) {
        // input
        int N, M, K;
        std::cin >> N >> M >> K;

        std::string S;
        std::cin >> S;
        
        std::vector<std::vector<int>> adj(M);
        for (int i = 0; i < M; i++) {
            int u, v;
            std::cin >> u >> v;
            u--; v--;
            adj[u].push_back(v); // directed
        }
        
        // solve
        std::vector<std::vector<int>> dp(2 * K, std::vector<int>(N, -1));
        for (int i = 0; i < N; i++) 
            dp[2 * K - 1][i] = (S[i] == 'A') ? 0 : 1; // A:0, B:1;
        
        for (int i = 2 * K - 2; i >= 0; i--) {
            for (int j = 0; j < N; j++) {
                if (i % 2 == 0) {
                    int res = 0;
                    for (int v : adj[j]) // B's turn
                        if (dp[i + 1][v] == 1) res = 1; // take 1 if possible
                    dp[i][j] = res;
                }
                else {
                    int res = 1;
                    for (int v : adj[j]) // A's turn
                        if (dp[i + 1][v] == 0) res = 0; // take 0 if possible
                    dp[i][j] = res;

                }
            }
        }

        // presetation
        int ans = 1;
        for (int v : adj[0]) if (dp[0][v] == 0) ans = 0; // A's first move
        if (ans == 0) std::cout << "Alice\n";
        else std::cout << "Bob\n";
    }
}
