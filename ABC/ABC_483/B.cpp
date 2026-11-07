#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::deque<P> dq;
    for (int i = 1; i <= N; i++) {
        dq.push_back({i, 1});
    }

    while (Q--) {
        int k;
        std::cin >> k;

        std::queue<P> q;
        while (k--) {
            auto [i, j] = dq.front(); dq.pop_front();
            q.emplace(i, -1 * j);
        }
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            dq.push_front(p);
        }
    }

    for (int i = 0; i < N; i++) {
        auto [a, b] = dq.front(); dq.pop_front();
        std::cout << a * b << "\n";
    }

    return 0;
}

