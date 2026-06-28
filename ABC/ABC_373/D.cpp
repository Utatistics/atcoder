#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--; v--;    
        adj[u].push_back({v, w});
    }
    

    return 0;
}

