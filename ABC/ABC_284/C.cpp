#include <bits/stdc++.h>

int N, M;
std::vector<std::vector<int>> adj; 
std::vector<bool> visited;

void dfs(int x) {
    if (visited[x]) return;
    visited[x] = true; // visited

    for (auto neighbor : adj[x]) {
        dfs(neighbor);
    }
}

int main() {
    // input
    int N, M;
    std::cin >> N >> M;

    adj.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
   // solve
    int ans = 0;
    visited.resize(N);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            ans++;
            dfs(i);
        }
    }

    // presentation
    std::cout << ans << std::endl;

    return 0;
}

