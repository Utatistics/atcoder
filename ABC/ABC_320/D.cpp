#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<ll, ll>;
using tup = std::tuple<int, int, int>;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<tup>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v, x, y;
        std::cin >> u >> v >> x >> y;
        u--; v--;

        adj[u].emplace_back(v, x, y);
        adj[v].emplace_back(u, -x, -y);
    }
    
    std::vector<P> G(N);
    std::vector<bool> visited(N, false);
    auto dfs = [&](auto f, int u) -> void {
        if (visited[u]) {
            return;
        }
        visited[u] = true; 
        auto [x, y] = G[u];
        for (auto [v, dx, dy] : adj[u]) {
            G[v] = {x + dx, y + dy};
            f(f, v);
        }
    };
    G[0] = {0, 0};
    dfs(dfs, 0);

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            std::cout << "undecidable\n";
            continue;
        }
        auto [x, y] = G[i];
        std::cout << x << " " << y << "\n";
    }
    return 0;
}



