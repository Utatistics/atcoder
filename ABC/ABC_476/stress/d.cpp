#include <bits/stdc++.h>

int main() {
    std::mt19937 rng(std::random_device{}());

    int N = std::uniform_int_distribution<int>(1, 8)(rng);
    int M = std::uniform_int_distribution<int>(1, 8)(rng);

    long long K = std::uniform_int_distribution<int>(2, 20)(rng);
    long long X = std::uniform_int_distribution<int>(0, 50)(rng);
    long long Y = std::uniform_int_distribution<int>(0, 8)(rng);

    std::cout << N << ' ' << M << ' ' << K << '\n';
    std::cout << X << ' ' << Y << '\n';

    for (int i = 0; i < N; i++) {
        long long A = std::uniform_int_distribution<int>(1, 50)(rng);
        std::cout << A << (i + 1 == N ? '\n' : ' ');
    }

    for (int i = 0; i < M; i++) {
        long long B = std::uniform_int_distribution<int>(1, 50)(rng);
        std::cout << B << (i + 1 == M ? '\n' : ' ');
    }
}
