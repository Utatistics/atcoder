#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        // input
        int N, D;
        std::cin >> N >> D;

        std::vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) std::cin >> A[i];
        for (int i = 0; i < N; i++) std::cin >> B[i];
        
        // solve
        std::deque<P> dq;
        for (int d = 0; d < N; d++) {
            // morning
            dq.push_back({A[d], d});
            
            // day
            int b = B[d];
            while (!dq.empty() && b > 0) {
                auto e = dq.front(); dq.pop_front(); // eggs
                if (b < e.first) {
                    dq.push_front({e.first - b, e.second});
                    b = 0;
                }
                else {
                    b -= e.first;
                }
            }

            // night
            if (!dq.empty()) {
                auto e = dq.front();
                if (d - e.second >= D) dq.pop_front();
            }
        }

        // presentation
        int ans = 0;
        while (!dq.empty()) {
            auto e = dq.front(); dq.pop_front();
            ans += e.first;
        }
        std::cout << ans << std::endl;

    }
    return 0;
}

