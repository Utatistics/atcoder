#include <bits/stdc++.h>

using ll = long long;

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        std::vector<int> R(N);
        for (int i = 0; i < N; i++) std::cin >> R[i];

        std::vector<int> A = R;
        for (int i = 0; i < N - 1; i++) // towards right
            A[i + 1] = std::min(A[i + 1], A[i] + 1); // min->higher, i + 1 lower than i
        for (int i = N - 1; i > 0; i--)  // towards left
            A[i - 1] = std::min(A[i - 1], A[i] + 1);

        ll ans = 0;
        for (int i = 0; i < N; i++) ans += R[i] - A[i];

        std::cout << ans << "\n";

    }

    return 0;
}

