#include <bits/stdc++.h>

using ll = long long;

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

    std::vector<std::vector<int>> C; // connected componets
    std::vector<int> m(N, -1); // to which componets
    std::vector<int> cnts; // edge count for comp

    auto bfs = [&](int s) -> void {
        if (m[s] >= 0) return;

        int i = (int)C.size();
        cnts.push_back(0);

        std::vector<int> c;
        std::queue<int> q;
        c.push_back(s);
        q.push(s);
        m[s] = i;

        while (!q.empty()) {
            int x = q.front(); q.pop();

            for (auto neighbor : adj[x]) {
                ++cnts[i];
                if (m[neighbor] >= 0) continue;

                c.push_back(neighbor);
                m[neighbor] = i;
                q.push(neighbor);
            }
        }

        cnts[i] /= 2;
        C.push_back(c);
    };

    for (int i = 0; i < N; i++) bfs(i);

    ll ans = 0;
    for (int i = 0; i < (int)C.size(); ++i) {
        int s = C[i].size();
        ans += 1LL * s * (s - 1) / 2 - cnts[i];
    }

    std::cout << ans << std::endl;
    return 0;
}
