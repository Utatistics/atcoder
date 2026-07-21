#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<int, ll>;

static const ll INF = (1LL << 60); // 1e18 is insufficient

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<P>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        std::cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    ll ans = INF;
    std::vector<bool> visited(N);
    auto dfs = [&](auto f, int u, ll x) -> void {
        if (u == N - 1) { // 0 index
            ans = std::min(ans, x);
            return;
        }

        visited[u] = true;
        for (auto [v, w] : adj[u]) {
            if (!visited[v]) 
                f(f, v, x ^ w);
        }
        visited[u] = false;
    };
    dfs(dfs, 0, 0);

    std::cout << ans << std::endl;
    return 0;
}
