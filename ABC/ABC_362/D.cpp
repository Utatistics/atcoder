#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<ll, int>; // {cost, to}

static const ll MAX = 1e18; // change if required

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    std::vector<std::vector<P>> adj(N); // {to, cost}
    for (int i = 0; i < M; i++) {
        int u, v, b;
        std::cin >> u >> v >> b;
        u--; v--;
        adj[u].push_back({v, b + A[v]});
        adj[v].push_back({u, b + A[u]});
    }
    
    std::vector<ll> d(N, MAX); // distance from s.
    
    auto dijkstra = [&](int s) {
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq; // min heap required
        
        d[s] = 0;
        pq.push({d[s], s}); // {cost, s}

        while (!pq.empty()) {
            auto [c, u] = pq.top(); pq.pop(); // the neighbor with the smallst cost
            if (c > d[u]) continue; // ignore if already computed
            
            int m = adj[u].size();
            for (int i = 0; i < m; i++) {
                auto [v, nc] = adj[u][i]; // {to, cost}
                if (d[u] + nc < d[v]) { // update iff smaller cost 
                    d[v] = d[u] + nc; // update
                    pq.push({d[v], v}); // {cost, to}
                }
            }
        }
    };

    dijkstra(0);

    for (int i = 1; i < N; i++) std::cout << d[i] + A[0] << " ";
    std::cout << std::endl;

    return 0;
}

