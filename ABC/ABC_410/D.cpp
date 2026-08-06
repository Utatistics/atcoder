#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N, M;
    std::cin >> N >> M;

    int W = 1<<10;

    std::vector<std::vector<P>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
    }

    std::vector<bool> visited(N * W, false);
    auto bfs = [&]() -> void {
        std::queue<int> q;

        q.push(0); // init
        
        while (!q.empty()) { 
            int uw = q.front(); q.pop();
            int u = uw / W, x = uw % W;
            for (auto [v, w] : adj[u]) {
                int vw = v*W + (x^w); // x^w = x XOR w
                if (visited[vw]) continue;
                visited[vw] = true;
                q.push(vw);
            }
        }
    };
    bfs();

    for (int i = 0; i < W; i++) {
        if (visited[(N - 1) * W + i]) {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}

