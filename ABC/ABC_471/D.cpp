#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int Q, V;
    std::cin >> Q >> V;

    std::priority_queue<P> pq;

    while (Q--) {
        int q, t;
        std::cin >> q >> t;

        if (q == 1) {
            int w;
            std::cin >> w;
            pq.emplace(w - t, t);
        }
        else {
            if (pq.empty()) {
                std::cout << -1 << "\n";
                continue;
            }

            auto [v, t_] = pq.top(); pq.pop();
            std::cout << std::min(V, v + t) << "\n";
        }
    }
    return 0;
}
