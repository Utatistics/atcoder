#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    return 0;
}

