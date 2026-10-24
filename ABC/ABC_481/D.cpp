#include <bits/stdc++.h>

static const int INF = 1e9 + 9;
using P = std::pair<int, int>;

int main() {
    int N, M, S, T;
    std::cin >> N >> M >> S >> T;
    --S;
    --T;
    
    std::vector<std::vector<P>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        adj[a].emplace_back(b, 1); // set cost to 1
    }
    
    std::vector<int> m(N, INF); // min map
    for (int a = 0; a < N; a++) {
        int minb = INF;
        for (auto [b, c] : adj[a]) {
            minb = std::min(minb, b);
        }
        m[a] = minb;
    }

    std::vector<int> dist(N, INF);
    auto dijkstra = [&](int s) { // O(E * logV)
        std::priority_queue<
            P,
            std::vector<P>,
            std::greater<P>> pq; // min heap required

        pq.emplace(0, s); // (distance, vertex)
        dist[s] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            for (auto [v, c] : adj[u]) {
                if (m[u] == v && m[u] != INF) {
                    c = 0;
                }
                if (dist[v] > dist[u] + c) { // better path found
                    dist[v] = dist[u] + c; // update
                    pq.emplace(dist[v], v);
                }
            }
        }
    };
    dijkstra(S);

    if (dist[T] == INF) {
        std::cout << -1 << std::endl;
    }
    else {
        std::cout << dist[T] << std::endl;
    }
    return 0;
}

