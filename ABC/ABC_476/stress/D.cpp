#include <bits/stdc++.h>

int main() {
    int N, M;
    long long K, X, Y;
    std::cin >> N >> M >> K;
    std::cin >> X >> Y;

    std::vector<long long> A(N), B(M);
    for (long long &x : A) {
        std::cin >> x;
    }
    for (long long &x : B) {
        std::cin >> x;
    }

    int ans = 0;

    for (int maskA = 0; maskA < (1 << N); maskA++) {
        long long dessert_cost = 0;
        int dessert_cnt = 0;

        for (int i = 0; i < N; i++) {
            if (maskA >> i & 1) {
                dessert_cost += A[i];
                dessert_cnt++;
            }
        }

        for (int maskB = 0; maskB < (1 << M); maskB++) {
            long long k_needed = 0;
            int drink_cnt = 0;

            for (int j = 0; j < M; j++) {
                if (maskB >> j & 1) {
                    k_needed += (B[j] + K - 1) / K;
                    drink_cnt++;
                }
            }

            if (k_needed > Y) {
                continue;
            }

            long long k_remaining = Y - k_needed;

            if (dessert_cost <= X + k_remaining * K) {
                ans = std::max(ans, dessert_cnt + drink_cnt);
            }
        }
    }

    std::cout << ans << '\n';
}
