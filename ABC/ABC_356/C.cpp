#include <bits/stdc++.h>

int main() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> R(M);
    std::vector<std::vector<int>> T(M);
    for (int i = 0; i < M; i++) {
        int C;
        std::cin >> C;
        for (int j = 0; j < C; j++) {
            int a;
            std::cin >> a;
            T[i].push_back(a);
        }
        std::cin >> R[i];
    }


    return 0;
}

