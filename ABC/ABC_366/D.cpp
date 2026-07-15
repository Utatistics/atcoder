#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> A(N * N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                std::cin >> A[i * N + j][k];    
            }
        }
    }

    std::vector<std::vector<int>> ps(N * N, std::vector<int>(N + 1, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 1; k <= N; k++) {
                ps[i * N + j][k] = ps[i * N + j][k - 1] + A[i * N + j][k - 1];    
            }
        }
    }

    int Q;
    std::cin >> Q;
    while (Q--) {
        ll ans = 0;
        int lx, rx, ly, ry, lz, rz;
        std::cin >> lx >> rx >> ly >> ry >> lz >> rz;
        --lx; --rx; --ly; --ry; // 0 index

        for (int i = lx; i <= rx; i++) {
           for (int j = ly; j <= ry; j++) {
               ans += ps[i * N + j][rz] - ps[i * N + j][lz - 1];
           } 
        }

        std::cout << ans << std::endl;    
    }

    return 0;
}

