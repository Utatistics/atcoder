#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        std::vector<int> A(2 * N);
        std::vector<std::vector<int>> p(N); //  positions
        for (int i = 0; i < 2 * N; i++) {
            std::cin >> A[i];
            --A[i];
            p[A[i]].push_back(i);
        }

        std::set<P> s;
        for (int i = 0; i < 2 * N - 1; i++) {
            int a = A[i]; int b = A[i + 1];
            if (a == b) continue;
            if (a > b) std::swap(a, b);
            s.insert({a, b});
        }

        int ans = 0;
        for (auto [a, b] : s) {
            int al = p[a][0], ar = p[a][1]; // A[al] = A[ar] 
            int bl = p[b][0], br = p[b][1]; // A[bl] = B[br]
            if (al+1 == ar) continue; // skip if next to each other
            if (bl+1 == br) continue;

            if (std::abs(al-bl) == 1 && std::abs(ar-br) == 1) ans++;
        }

        std::cout << ans << "\n";

    }
    return 0;
}

