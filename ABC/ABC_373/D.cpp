#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<int, int>;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<P>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--; v--;    
        adj[u].push_back({v, w});
        adj[v].push_back({u, -w});
    }

    std::vector<ll> X(N, 0);
    std::vector<bool> visited(N, false);
    
    auto dfs = [&](auto f, int u) {
        if (visited[u]) return;
        visited[u] = true;

        for (auto [v, w] : adj[u]) {
            // if (visited[v]) continue;
            X[v] = X[u] + w;
            f(f, v);
        }
    };

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        dfs(dfs, i);
    }

    for (ll u : X) std::cout << u << " ";
    std::cout << std::endl;

    return 0;
}

