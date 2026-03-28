#include <bits/stdc++.h>

using ll = long long;

struct Edge { int to; int weight;};

int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<Edge>> adj(V);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Min-heap: (weight, vertex)
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int,int>>,
                        std::greater<std::pair<int,int>>> pq;

    std::vector<bool> visited(V, false);
    ll ans = 0;

    // Start from vertex 0
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        ans += w;

        for (const auto &e : adj[u]) {
            if (!visited[e.to]) {
                pq.push({e.weight, e.to});
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
