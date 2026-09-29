#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> adj(N);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        --a;
        adj[i] = a;
    }
    std::vector<int> visited(N, false);

    bool flg = false;
    auto bfs = [&](int sx) -> auto {
        std::queue<int> q;
        std::vector<int> p; // path
        std::vector<int> lv(N, -1); // local visited
        
        q.push(sx);
        p.push_back(sx);
        lv[sx] = 0;

        int i = 0; int j = -1;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            int nx = adj[x];

            if (visited[nx]) continue;
            // std::cout << x + 1 << "->" << nx + 1 << std::endl;

            if (lv[nx] > 0) {
                j = lv[nx];
                flg = true;
                break;
            }
            q.push(nx);
            p.push_back(nx);
            lv[nx] = ++i;
        }

        std::vector<int> ans(p.begin() + j, p.end());
        return ans;
    };

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        auto ans = bfs(i);

        if (flg) {
            std::cout << (int)ans.size() << std::endl;
            for (auto x : ans) {
                std::cout << x + 1 << " ";
            }
            std::cout << std::endl;
            break;
        }
        for (auto x : ans) {
            visited[x] = true;
        }
    }
    return 0;
}

