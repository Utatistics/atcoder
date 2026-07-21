#include <bits/stdc++.h>

using P = std::pair<int, int>;
static const int INF = 1e9;

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, P>> X(N);
    for (int i = 0; i < N; i++) {
        int a, c;
        std::cin >> a >> c;
        X[i] = {a, {c, i}};
    }
    std::sort(X.begin(), X.end()); // ascending by a

    int ans = N;
    std::vector<bool> A(N, true); // survive or not
    std::vector<int> C(N, INF);
    for (int i = N - 1; 0 <= i; i--) {
        auto [a, p] = X[i];
        auto [c, j] = p; // j: orig index

        if (i == N - 1) C[i] = c;
        else C[i] = std::min(C[i + 1], c);

        if (c != C[i]) {
            A[j] = false;
            --ans;
        }
    }

    std::cout << ans << std::endl;
    for (int i = 0; i < N; i++) {
        if (A[i]) std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
    return 0;
}

