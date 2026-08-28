#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) std::cin >> A[i];
    for (int i = 0; i < M; i++) std::cin >> B[i];

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int u = A[i] - 1;
        int v = B[i] - 1;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> col(N, -1);
    auto dfs = [&](auto f, int u, int c) -> bool {
        if (col[u] >= 0) {
            return col[u] == c;
        }

        col[u] = c;
        for (auto v : adj[u]) {
            if (!f(f, v, !c)) return false;
        }
        return true;
    };

    for (int i = 0; i < N; i++) {
        if (col[i] >= 0) continue;
        if (!dfs(dfs, i, 0)) {
            std::cout << "No\n";
            return 0;
        }
    }

    std::cout << "Yes\n";
    return 0;
}
