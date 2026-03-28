#include <bits/stdc++.h>

int main() {
    // input
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> A(N, std::vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            std::cin >> A[i][j];
        }
    }

    // solve

    return 0;
}

