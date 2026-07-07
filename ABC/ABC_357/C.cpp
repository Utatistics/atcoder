#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int c = N;
    int K = 1;
    while (c--) K *= 3;

    std::vector<std::vector<char>> A(K, std::vector<char>(K));
    for (int i = 0; i < K; i += K) {
        for (int j = 0; j < K; j += K) {
            for (int k = 0; k < 9; k++) {
                int r = i + (k / 3);
                int c = j + (k % 3);
                char x = std::abs(k - 0) == std::abs(k - 8) ? '.' : '#';
                A[r][c] = x;
            }
        }
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            std::cout << A[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}

