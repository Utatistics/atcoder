#include <iostream>
#include <queue>
#include <algorithm>

using ll = long long;
using P = std::pair<ll, int>;
static const ll MAX = 1e15;

struct edge { // to a city
    int to;
    int a; // jpy
    int b; // snuuke
};

std::vector<ll> dijkstra(int s, char flg, std::vector<std::vector<edge>> &adj) {
    // init
    int n = adj.size();

    std::vector<ll> d(n); // distance
    for (int i = 0; i < n; i++) d[i] = (i == s) ? 0 : MAX;
    
    // nin heap required
    std::priority_queue<P, std::vector<P>,std::greater<P>> pq;
    pq.push({0, s}); // (distance, vertex)
    
    // serach 
    while (!pq.empty()) {
        // retrieve information
        auto p = pq.top();
        int dist_u = p.first;
        int u = p.second;
        pq.pop(); // remove
        
        if (dist_u > d[u]) continue; // skip outdated node
        for (int i = 0; i < (int)adj[u].size(); i++) { // given u, visit v for relaxation
            edge e = adj[u][i];
            int v = e.to;
            ll cost = (flg == 'a') ? e.a : e.b;
            if (d[u] + cost < d[v]) {
                d[v] = d[u] + cost;
                pq.push(std::make_pair(d[v], v));
            }
        }
    }
    
    return d;
}

int main () {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    s--; t--; // origin 0 1 -> 0

    // input processing
    std::vector<std::vector<edge>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, a, b;
        std::cin >> u >> v >> a >> b;
        u--; v--; // origin 1 -> 0
        adj[u].push_back({v, a, b});
        adj[v].push_back({u, a, b});
    }

    // solve
    std::vector<ll> da = dijkstra(s, 'a', adj); // O(m * logn), m ~ 10*5
    std::vector<ll> db = dijkstra(t, 'b', adj); // O(m * logn)

    std::vector<ll> ans(n);
    for (int i = 0; i < n; i++) ans[i] = MAX - (da[i] + db[i]);
    // create suffix maximum array
    for (int i = n - 2; i >= 0; --i) ans[i] = std::max(ans[i], ans[i+1]); // O(N)
    
    // presentation
    for (int i = 0; i < n; i++) std::cout << ans[i] << "\n";

    return 0;
}
