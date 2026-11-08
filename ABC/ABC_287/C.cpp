#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> cnt(N, 0);

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        --a; --b;

        ++cnt[a];
        ++cnt[b];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (M != N - 1) {
        std::cout << "No\n";
        return 0;
    }

    bool ans = true;
    std::vector<bool> visited(N, false);

    auto dfs = [&](auto&& f, int u) -> void {
        visited[u] = true;
        if (cnt[u] > 2) ans = false;

        for (auto v : adj[u]) {
            if (!visited[v]) {
                f(f, v);
            }
        }
    };

    dfs(dfs, 0);
    for (int i = 0; i < N; i++) if (!visited[i]) ans = false;

    std::cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}
