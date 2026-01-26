#include <bits/stdc++.h>

using ll = long long;

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
    ll ans;
    for (int i = 0; i < N; i++) { // compupte nC3
        ll n = N - adj[i].size() - 1;
        if (n < 3) {
            ans = 0;
            std::cout << ans << " ";
        }
        else {
            ans = n * (n - 1) * (n - 2) / 6;
            std::cout << ans << " ";
        } 
    }
    std::cout << std::endl;

    return 0;
}

