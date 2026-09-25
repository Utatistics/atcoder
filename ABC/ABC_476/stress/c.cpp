#include <bits/stdc++.h>

int main() {
    std::mt19937 rng(std::random_device{}());
    int N = std::uniform_int_distribution<int>(3, 20)(rng);

    std::cout << N << '\n';
    for (int i = 0; i < N; i++) {
        int x = std::uniform_int_distribution<int>(1, 10)(rng);
        std::cout << x << (i + 1 == N ? '\n' : ' ');
    }

    return 0;
}
