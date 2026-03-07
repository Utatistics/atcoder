#include <bits/stdc++.h>

// global
int N, M;
std::vector<std::vector<int>> adj;
std::vector<bool> status;
bool ans;

void dfs(int x, int d) { 
    if (!ans) return;
    if (d == N) return; // cyclic path count
    if ((int)adj[x].size() != 2) { // no branch
        ans = false;
        return;
    }
    if (status[x]) return; // no going back

    // search
    status[x] = true; // visited  
    for (auto neighbor : adj[x]) {
        dfs(neighbor, d + 1);
    }
}

int main() {
    // inpur
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
    ans = true;
    status.assign(N, false);
    dfs(0, 0);

    // presentation
    for (int i = 0; i < N; i++) if (!status[i]) ans = false; // connectivity
    if (ans) std::cout << "Yes\n"; 
    else std::cout << "No\n"; 

    return 0;
}
