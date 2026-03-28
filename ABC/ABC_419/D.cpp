#include <bits/stdc++.h>

int main() {
    // input processing
    int N, M;
    std::cin >> N >> M;

    std::string S, T;
    std::cin >> S >> T;

    // solve
    std::vector<int> imos(N + 1, 0);
    for (int i = 0; i < M; i++) { // 1dim imos
        int l, r;
        std::cin >> l >> r;
        l--; r--; // 0 index
        imos[l] += 1;
        imos[r + 1] += -1;
    }

    std::vector<int> A(N + 1);
    for (int i = 0; i < N; i++)
        A[i] = (i == 0) ? imos[i] : A[i - 1] + imos[i];
    
    // presentation
    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 0) std::cout << S[i];
        else std::cout << T[i];
    }
    std::cout << std::endl;
    
    return 0;
}

