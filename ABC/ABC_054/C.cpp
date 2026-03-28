#include <bits/stdc++.h>

int N, M;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;

void dfs(int u, int &res) {
    bool eog = true; // end of graph
    for (int i = 0; i < N; ++i) 
        if (!visited[i] && i != u) eog = false;
    if (eog) {
        ++res;
        return;
    }

    visited[u] = true;
    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v, res);
    }
    visited[u] = false; // go back to the branch
}

int main() {
    std::cin >> N >> M;
    
    adj.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    visited.assign(N, false);
    int ans = 0;
    dfs(0, ans);
    std::cout << ans << std::endl;
}
