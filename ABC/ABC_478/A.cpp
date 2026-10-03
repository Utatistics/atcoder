#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N, 0);
    int i = 0;
    while (M) {
        A[i % N]++;
        --M;
        ++i;
    }
    for (int i = 0; i < N; i++) {
        std::cout << A[i] << std::endl;
    }

    return 0;
}

