#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    std::vector<int> L(N, 1), R(N, 1);
    for (int i = 1; i < N; i++) {
        L[i] = std::min(A[i], L[i - 1] + 1);
    }
    for (int i = N - 2; i >= 0; i--) {
        R[i] = std::min(A[i], R[i + 1] + 1);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = std::max(ans, std::min(L[i], R[i]));
    }
    std::cout << ans << std::endl;
    return 0;
}

