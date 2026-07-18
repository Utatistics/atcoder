#include <bits/stdc++.h>

int main() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<char> R(M);
    std::vector<std::unordered_set<int>> T(M);
    for (int i = 0; i < M; i++) {
        int C;
        std::cin >> C;
        for (int j = 0; j < C; j++) {
            int a;
            std::cin >> a;
            T[i].insert(a);
        }
        std::cin >> R[i];
    }

    int ans = 0;
    for (int i = 0; i < (1 << N); i++) { // subset from 0 to 2^N - 1
        
        bool flg = true;
        for (int t = 0; t < M; t++) {
            int k = 0;
            for (int j = 0; j < N; j++) {
                if ((i & (1 << j)) && T[t].count(j + 1) > 0)
                    ++k;
            }
            if (R[t] == 'o' && k < K) {
                flg = false;
                break;
            }
            if (R[t] == 'x' && k >= K) {
                flg = false;
                break;
            }
        }
        if (flg) ++ans;
    }

    std::cout << ans << '\n';
    return 0;
}
