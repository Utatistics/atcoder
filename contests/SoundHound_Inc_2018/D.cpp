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

ll dijkstra(int s, int t, char flg, std::vector<std::vector<edge>> &adj) {
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
        
        // skip outdated entry
        if (dist_u > d[u]) continue;

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
    return d[t];
}

int main () {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;

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
    std::vector<ll> ans;
    for (int i = 0; i < n; i++) { // N ~ 10*5
        int a = dijkstra(s, i, 'a', adj); // O(m * logn)
        int b = dijkstra(i, t, 'b', adj); // O(m * logn)
        // debug
        std::cout << "a=" << a << ", b=" << b << std::endl;
        ans.push_back(MAX - a - b);
    }
    // create suffix maximum array
    for (int i = 0; i < n; i++) std::cout << ans[i] << " ";
    std::cout << std::endl;
    for (int i = n - 2; i >= 0; --i) ans[i] = std::max(ans[i], ans[i+1]); // O(N)
    for (int i = 0; i < n; i++) std::cout << ans[i] << " ";
    std::cout << std::endl;

    return 0;
}
