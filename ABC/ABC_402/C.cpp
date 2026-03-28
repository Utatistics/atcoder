#include <bits/stdc++.h>

int main() {
    // input
    int N, M;
    std::cin >> N >> M;

    std::vector<int> c(M, 0);
    std::unordered_map<int, std::vector<int>> m;
    for (int i = 0; i < M; i++) {
        int K;
        std::cin >> K;
        c[i] += K;

        for (int j = 0; j < K; j++) {
            int a;
            std::cin >> a;
            a--;
            m[a].push_back(i);
        }
    }

    std::vector<int> B(N);
    for (int i = 0; i < N; i++) {
        int b;
        std::cin >> b;
        b--; // 0 index
        B[i] = b;
    }

    // solve
    int ans = 0;
    for (auto x : B) {
        for (auto y : m[x]) {
            c[y]--;
            if (c[y] == 0) ans++;
        }

        // presentation
        std::cout << ans << std::endl;

    }

    return 0;
}

