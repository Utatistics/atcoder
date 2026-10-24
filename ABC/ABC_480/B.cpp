#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) std::cin >> S[i];
    std::vector<std::string> T(M);
    for (int i = 0; i < M; i++) std::cin >> T[i];


    std::vector<int> ans(N, 0);
    for (int j = 0; j < M; j++) {
        int cnt0 = 0, idx = -1;

        for (int i = 0; i < N; i++) {
            if (S[i] == T[j]) {
                ++cnt0;
                idx = i;
            }
        }
        if (cnt0 == 1) {
            ++ans[idx];
            continue;
        }

        if (cnt0 > 0) continue;

        for (int i = 0; i < N; i++) {
            int n = S[i].size();
            int m = T[j].size();
            if (n != m) continue;

            int cnt1 = 0;
            for (int k = 0; k < n; k++) {
                if (S[i][k] != T[j][k]) ++cnt1;
            }

            if (cnt1 == 1) {
                ++cnt0;
                idx = i;
            }
        }

        if (cnt0 == 1) ++ans[idx];
    }

    for (int i = 0; i < N; i++) {
        std::cout << ans[i] << '\n';
    }

    return 0;
}
