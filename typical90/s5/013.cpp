#include <bits/stdc++.h>

using P = std::pair<int, int>;
static const int INF = 1e9; // change if required

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<P>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--; b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    auto dijkstra = [&](int t, auto& dist) { // O(E * logV)
        std::priority_queue<
            P,
            std::vector<P>,
            std::greater<P>> pq; // min heap required
        
        pq.emplace(0, t); // (distance, vertex)
        dist[t] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue; // skip outdated node, try if same (for init)
            
            for (auto [v, c] : adj[u]) {

                if (dist[v] > dist[u] + c) { // better path found
                    dist[v] = dist[u] + c; // update
                    pq.emplace(dist[v], v);
                }
            }
        }
    };
    
    std::vector<int> distN(N, INF); // distance array
    std::vector<int> dist1(N, INF); // distance array
    dijkstra(N - 1, distN);
    dijkstra(0, dist1);

    for (int k = 0; k < N; k++) {
        int ans = dist1[k] + distN[k];
        std::cout << ans << "\n";
    }

    return 0;
}

