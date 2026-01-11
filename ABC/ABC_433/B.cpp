#include <bits/stdc++.h>

int main() {
    // input processing
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    // solve
    std::cout << -1 << std::endl;

    for (int i = 1; i < N; i++) {
        int ans = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] > A[i]) {
                ans = j + 1;
                break;
            }
        }
        std::cout << ans << std::endl;
    }

    return 0;
}

