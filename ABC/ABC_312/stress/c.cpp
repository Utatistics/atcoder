#include <bits/stdc++.h>

int main() {

    /* generator */
    std::mt19937 rng(std::random_device{}());

    int N = std::uniform_int_distribution<int>(1, 20)(rng);
    int M = std::uniform_int_distribution<int>(1, 20)(rng);

    std::vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) {
        int a = std::uniform_int_distribution<int>(1, 100000)(rng);
        
    }
    return 0;
}

