#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N, D;
    std::cin >> N >> D;

    std::vector<P> p;
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        p.emplace_back(x, y);
    }

    std::vector<bool> visited(N, false);
    auto bfs = [&]() -> void { // O(N^2)
        std::queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            auto [x, y] = p[i];
            for (int j = 0; j < N; j++) {
                if (visited[j]) continue;

                auto [nx, ny] = p[j];
                int dx = nx - x;
                int dy = ny - y;

                if (dx * dx + dy * dy <= D * D) {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    };
    bfs();

    for (int i = 0; i < N; i++) {
        std::cout << (visited[i] ? "Yes\n" : "No\n");
    }

    return 0;
}
