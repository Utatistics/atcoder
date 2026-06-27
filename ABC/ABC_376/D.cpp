#include <bits/stdc++.h>

static const int MAX = 1e9;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A;
    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);

        if (v == 0) A.push_back(u);
    }

    std::vector<int> d(N, -1);
    auto bfs = [&](int s) -> void {
        std::queue<int> q;
        
        q.push(s); // init
        d[s] = 0;

        while (!q.empty()) { 
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (d[v] >= 0) continue;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    };

    bfs(0);

    int ans = MAX;
    for (int x : A) {
        if (d[x] < 0) continue;
        ans = std::min(ans, d[x] + 1);
    }

    if (ans == MAX) std::cout << -1 << std::endl;
    else std::cout << ans << std::endl;
    
    return 0;
}

