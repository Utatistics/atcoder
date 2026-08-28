#include <bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
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

        std::vector<int> cols(N, -1);
        std::vector<int> vs;
        auto dfs = [&](auto f, int u, int c) -> bool {
            if (cols[u] != -1) {
                if (cols[u] != c) { // color conflict
                    std::reverse(vs.begin(), vs.end());
                    while (vs.back() != u) vs.pop_back();
                    return true;
                }
                return false; // no conflict
            }
            vs.push_back(u);
            cols[u] = c;
            for (int v : adj[u]) {
                if (f(f, v, !c)) return true; // dfs ends 
            }
            vs.pop_back(); // roll back 
            return false;
        };
        dfs(dfs, 0, 0);

        if (vs.size()) {
            std::cout << vs.size() << "\n";
            for (int v : vs) std::cout << v + 1 << " ";
            std::cout << "\n";    
        }
        else std::cout << -1 << "\n";    
    }
    return 0;
}

