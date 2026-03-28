#include <bits/stdc++.h>

int N, M;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;

int n, m;

void dfs(int u) {
    visited[u] = true;
    n++;
    m += adj[u].size();

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    // input
    std::cin >> N >> M;

    adj.resize(N);
    visited.assign(N, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--; // convert to 0-based
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // solve
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) { // visit a connected graph once 
            n = 0;
            m = 0;
            
            dfs(i);
            m /= 2; // each edge counted twice
            
            if (m == n - 1) ans++; // true if graph is a tree.
        }
    }

    // presentation
    std::cout << ans << std::endl;
    return 0;
}
