#include <bits/stdc++.h>

using ll = long long;
using p = std::pair<int, int>;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<p>> adj(N);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        --a; --b;

        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    ll ans = 0;
    std::vector<bool> visited(N, false);
    auto dfs = [&](auto f, int u, ll c) -> void {
        visited[u] = true;
        ans = std::max(ans, c);

        for (auto [v, w] : adj[u]) {
            if (visited[v]) continue;
            f(f, v, c + w);
        }
        visited[u] = false; // return
    };

    for (int i = 0; i < N; i++) {
        dfs(dfs, i, 0);
    }

    std::cout << ans << '\n';
}

