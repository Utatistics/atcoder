#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<ll, int>;

static constexpr ll INF = 1e18;

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<P>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b, x;
        std::cin >> a >> b >> x;
        x--;
        
        adj[i].emplace_back(a, i + 1);
        adj[i].emplace_back(b, x);
    }
    
    std::vector<ll> dist(N, INF);
    auto dijkstra = [&](int i) -> void {
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq; // min heap required
        
        pq.emplace(0, i); // (distance, vertex)
        dist[i] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (dist[u] < d) continue; // inferior path
            
            for (auto [c, v] : adj[u]) {
                if (dist[v] > dist[u] + c) { // better path found
                    dist[v] = dist[u] + c;
                    pq.emplace(dist[v], v);
                }
            }
        }
    };
    dijkstra(0);

    std::cout << dist[N - 1] << std::endl;
    return 0;
}

