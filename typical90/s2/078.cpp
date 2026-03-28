#include <bits/stdc++.h>

auto bfs(int s, const std::vector<std::vector<int>> &adj) {
    int N = adj.size();
    std::queue<int> q;
    std::vector<bool> status(N, false);
    
    status[s] = true;
    q.push(s);

    std::vector<int> res(N, 0); // cnt table to be returned
    while (!q.empty()) {
        int x = q.front(); q.pop();

        for (auto neighbor : adj[x]) {
            if (x < neighbor) res[neighbor]++;// Count each undirected edge exactly once

            if (!status[neighbor]) {
                status[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return res;
}

int main() {
    // input processing
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
         u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // solve
    auto res = bfs(0, adj);

    // presentation
    int ans = 0;
    for (int c : res) ans += (c == 1) ? 1 : 0;
    std::cout << ans << std::endl;

    return 0;
}
