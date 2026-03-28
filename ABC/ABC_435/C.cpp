#include <bits/stdc++.h>

int main() {
    // input processing
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    // solve
    int k = A[0] - 1; // must fallen 
    for (int i = 1; i < N; i++) {
        if (i > k) break;
        k = std::max(k, i + A[i] - 1);
    }

    std::cout << std::min(k + 1, N) << std::endl;
    return 0;
}

