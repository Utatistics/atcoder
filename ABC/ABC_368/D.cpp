#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int r = -1;
    std::vector<int> A(N, -1);
    for (int i = 0; i < K; i++) {
        int v;
        std::cin >> v;
        --v;
        A[v] = 1;

        if (i == 0) r = v; // root
    } 

    int ans = 0;
    auto dfs = [&](auto f, int x, int p) -> bool {
        bool flg = A[x] > 0;

        for (auto neighbor : adj[x]) {
            if (neighbor == p) continue;
            flg |= f(f, neighbor, x);
        }

        if (flg) ++ans;
        return flg;
    };

    dfs(dfs, r, -1);
    std::cout << ans << std::endl;
}

