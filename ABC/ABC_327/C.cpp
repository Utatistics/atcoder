#include <bits/stdc++.h>

int main() {
    int N = 9;

    std::vector<std::vector<int>> A(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> A[i][j];
            A[i][j]--; // 0 origin
        }
    }

    std::vector<bool> R(N);
    for (int i = 0; i < N; i++) {
        bool flg = true;
        std::vector<int> cnt(N, 0);
        for (int j = 0; j < N; j++) {
            if (cnt[A[i][j]] > 0) flg = false;
            cnt[A[i][j]]++;
        }
        if (flg) R[i] = true;
    }
    std::vector<bool> C(N);
    for (int j = 0; j < N; j++) {
        bool flg = true;
        std::vector<int> cnt(N, 0);
        for (int i = 0; i < N; i++) {
            if (cnt[A[i][j]] > 0) flg = false;
            cnt[A[i][j]]++;
        }
        if (flg) C[j] = true;
    }

    std::vector<bool> B;
    for (int i = 0; i < N; i+=3) {
        for (int j = 0; j < N; j+=3) {
            bool flg = true;
            std::vector<int> cnt(N, 0);
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    if (cnt[A[i + r][j + c]] > 0) flg = false;
                    cnt[A[i + r][j + c]]++;
                }
            }
            B.push_back(flg);
        }
    }

    std::string ans = "Yes\n";
    for (int i = 0; i < N; i++) {
        if (!R[i]) ans = "No\n";
    }
    for (int i = 0; i < N; i++) {
        if (!C[i]) ans = "No\n";
    }
    for (int i = 0; i < N; i++) {
        if (!B[i]) ans = "No\n";
    }
    std::cout << ans;
    return 0;
}

