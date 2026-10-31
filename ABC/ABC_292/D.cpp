#include <bits/stdc++.h>

int main() {
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
 
    std::vector<std::vector<int>> C; // connected components
    std::vector<int> m(N, -1); // m[v] = connected component index containing v

    auto bfs = [&](int s) -> void {
        if (m[s] >= 0) return;

        int i = (int)C.size(); // ith cc
        std::vector<int> c; // cc nodes
        std::queue<int> q;

        m[s] = i;
        c.push_back(s);
        q.push(s);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (auto v : adj[u]) { // define adj list
                if (m[v] >= 0) continue;
                m[v] = i;
                c.push_back(v);
                q.push(v);
            }
            
        }

        C.push_back(c); // add a component
    };
    for (int i = 0; i < N; i++) bfs(i); // O(N + M)

    bool ans = true;
    for (auto c : C) { // O(N)
        int cnt = 0;
        for (auto x : c) {
            cnt += (int)adj[x].size();
        }
        if (cnt != 2 * (int)c.size()) {
            ans = false;
            break;
        }
    }
    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

