#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> X(N);
    for (int i = 0; i < N; i++) std::cin >> X[i];

    if (N == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    for (int k = 0; k < N; k++) {
        int ans = 1 << 30;

        if (k > 0) { // zombi goes to left
            ans = std::min(ans, std::max((X[k] - X[0]) / 2, (X[N - 1] - X[k - 1]) / 2));
        }
        if (k + 1 < N) { // zombi goes to right
            ans = std::min(ans, std::max((X[k + 1] - X[0]) / 2, (X[N - 1] - X[k]) / 2));
        }
        std::cout << ans << "\n";
    }
    return 0;
}

