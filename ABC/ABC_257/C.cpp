#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<P> W(N);
    for (int i = 0; i < N; i++) {
        int w;
        std::cin >> w;
        W[i] = {w, S[i] - '0'};
    }

    std::sort(W.begin(), W.end());
    
    std::vector<int> A(N + 1, 0), B(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        auto [w, s] = W[i - 1];
        A[i] = A[i - 1] + (s == 0);
    }
    for (int i = N - 1; i >= 0; i--) {
        auto [w, s] = W[i];
        B[i] = B[i + 1] + (s == 1);
    }

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        if (i > 0 && i < N && W[i - 1].first == W[i].first) continue;
        ans = std::max(ans, A[i] + B[i]);
    }

    std::cout << ans << std::endl;
    return 0;
}
