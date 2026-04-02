#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<int, int>;

std::vector<std::vector<P>> adj;
std::vector<int> C; // 0: white, 1: black

void dfs(int u, int p, long long d) {
    C[u] = d % 2; // color purely based on distance
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        dfs(v, u, d + w);
    }
}

int main() {
    int N;
    std::cin >> N;

    adj.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // solve
    C.resize(N, -1);
    C[0] = 0;

    dfs(0, -1, 0);

    // presentation
    for (int c : C) std::cout << c << "\n";
    return 0;
}

