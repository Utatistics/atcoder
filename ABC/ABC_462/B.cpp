#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int K;
        std::cin >> K;

        for (int j = 0; j < K; j++) {
            int a;
            std::cin >> a;
            --a;
            A[a].push_back(i + 1);
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << (int)A[i].size() << " ";
        for (int x : A[i]) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
