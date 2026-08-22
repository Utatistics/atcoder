#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto bfs = [&](int s) -> int {
        std::set<int> st;
        std::queue<int> q;

        q.push(s);
        st.insert(s);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (auto v : adj[u]) {
                if (st.count(v)) continue;
                if (v == 0) continue;  // don't enter vertex 1

                q.push(v);
                st.insert(v);
            }
        }

        return st.size();
    };

    if ((int)adj[0].size() == 1) {
        std::cout << 1 << std::endl;
        return 0;
    } 
    
    int M = 0;
    for (auto i : adj[0]) 
        M = std::max(M, bfs(i));
    std::cout << N - M << std::endl;
    return 0;
}

