#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<P> C;
    for (int i = 0; i < N + M; i++) {
        int c;
        std::cin >> c;

        C.emplace_back(c, i);
    }
    std::sort(C.begin(), C.end());

    std::vector<int> A(N);
    std::vector<int> B(M);
    for (int i = 0; i < N + M; i++) {
        auto [_, j] = C[i];
        
        if (j < N) A[j] = i;
        else B[j - N] = i;
    }

    for (int i = 0; i < N; i++) std::cout << A[i] + 1 << " ";
    std::cout << std::endl;
    for (int i = 0; i < M; i++) std::cout << B[i] + 1 << " ";
    std::cout << std::endl;
    
    return 0;
}

