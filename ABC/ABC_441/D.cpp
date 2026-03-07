#include <bits/stdc++.h>

using P = std::pair<int, int>;

// gloabl
int N, M, L, S, T;
std::vector<std::vector<P>> adj;
std::vector<bool> flg;

void dfs(int x, int d, int c) { // loc, depths, cost
    if (d == L)  {
        if (S <= c && c <= T) flg[x] = true;
        return;
    }

    for (auto [neighbor, cost] : adj[x]) {
        dfs(neighbor, d + 1, c + cost);
    }
}

int main() {
    // input
    std::cin >> N >> M >> L >> S >> T;
    
    adj.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        u--; v--;
        
        adj[u].push_back({v, c});
    }

    // solve
    flg.assign(N, false);
    dfs(0, 0, 0);

    // presentation
    for (int i = 0; i < N; i++) if (flg[i]) std::cout << i + 1 << " ";
    std::cout << std::endl;

    return 0;
}

