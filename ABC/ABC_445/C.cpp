#include <bits/stdc++.h>

auto bfs(int s, const std::vector<std::vector<int>> &adj, int N) {
    std::vector<bool> status(N);
    std::queue<int> q;

    status[s] = true;
    q.push(s);

    std::vector<int> v; // visited
    while (!q.empty()) {
        int x = q.front(); q.pop();

        for (auto neighbor : adj[x]) {
            if (status[neighbor]) continue; // ignore if visited
            status[neighbor] = true; // visited
            v.push_back(neighbor);
            q.push(neighbor);
        }
    }
    return v;
}

int main() {
    // input processing
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    // solve
    std::vector<int> c; // converge point
    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < N; i++) {
        int u = i;
        int v = A[i] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);

        if (u == v) c.push_back(u);
    }

    std::vector<int> ans(N, -1);
    for (auto x : c) {
        auto v = bfs(x, adj, N);
        for (int y : v) ans[y] = x;
    }

    // presentation
    for (int i = 0; i < N; i++) {
        if (ans[i] > 0) std::cout << ans[i] + 1 << " ";
        else std::cout << i + 1 << " ";
    }
    std::cout << std::endl;

    return 0;
}
