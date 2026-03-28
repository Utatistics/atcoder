#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> m0(M, 0);
    std::vector<int> m1(M, 0);

    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        m0[a]++;
        m1[b]++;
    }

    for (int i = 0; i < M; i++) {
        std::cout << m1[i] - m0[i] << std::endl;
    }

    return 0;
}

