#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        A[i] = a - 1; // 0 origin
    }
    std::vector<int> W(N);
    for (int i = 0; i < N; i++) std::cin >> W[i];

    std::vector<int> max(N, 0);
    std::map<int, int> m;
    for (int i = 0; i < N; i++) {
        m[A[i]] += W[i];
        max[A[i]] = std::max(max[A[i]], W[i]);
    }

    int ans = 0;
    for (auto [k, v] : m) {
        if (v > 0) ans += v - max[k];
    }

    std::cout << ans << std::endl;

    return 0;
}

