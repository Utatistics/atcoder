#include <bits/stdc++.h>

int main() {
    int N0, N1, M;
    std::cin >> N0 >> N1 >> M;

    int N = N0 + N1;
    std::vector<std::vector<int>> adj(N0 + N1);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    auto bfs = [&](int s) -> int {
        std::queue<int> q;
        std::vector<int> dist(N, -1);

        q.push(s);
        dist[s] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();

            for (auto v : adj[u]) {
                if (dist[v] >= 0) continue;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }

        int ans = -1;
        for (int i = 0; i < N; i++) {
            ans = std::max(ans, dist[i]);
        }
        return ans;
    };

    int du = bfs(0);
    int dv = bfs(N - 1);

    std::cout << 1 + du + dv << std::endl;

    return 0;
}

