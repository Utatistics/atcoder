#include <bits/stdc++.h>

static const int L = 2e3;

struct cl {int u; int d; int l; int r;}; // fixed syntax

int main() {
    // input processing
    int N;
    std::cin >> N;

    std::vector<cl> cls(N);
    std::vector<std::vector<int>> imos(L + 1, std::vector<int>(L + 1, 0));

    int n = N;
    while (n--) { // construct imosi
        int u, d, l, r;
        std::cin >> u >> d >> l >> r;
        u--; d--; l--; r--; // 1 to 0 origin

        cl c = {u, d, l, r};
        cls[N - (n + 1)] = c;

        imos[u][l]++;
        imos[u][r + 1]--;
        imos[d + 1][l]--;
        imos[d + 1][r + 1]++;
    }

    std::vector<std::vector<int>> A(L, std::vector<int>(L));
    for (int i = 0; i < L; i++) { // imos →
        for (int j = 0; j < L; j++) {
            if (j == 0) A[i][j] = imos[i][j];
            else A[i][j] = A[i][j - 1] + imos[i][j];
        }
    }
    for (int j = 0; j < L; j++) { // imos ↓
        for (int i = 0; i < L; i++) {
            if (i == 0) A[i][j] = A[i][j];
            else A[i][j] = A[i - 1][j] + A[i][j];
        }
    }

    int ans = L * L;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            if (A[i][j] > 0) ans--;
            if (A[i][j] != 1) A[i][j] = 0;
        }
    }

    std::vector<std::vector<int>> B(L + 1, std::vector<int>(L + 1, 0));
    for (int i = 1; i <= L; i++) { // 2d pref →
        for (int j = 1; j <= L; j++) {
            B[i][j] = B[i][j - 1] + A[i - 1][j - 1];
        }
    }
    for (int j = 1; j <= L; j++) { // 2d pref →
        for (int i = 1; i <= L; i++) {
            B[i][j] += B[i - 1][j];
        }
    }

    // presentation
    for (int k = 0; k < N; k++) {
        cl c = cls[k];
        c.u++; c.d++; c.l++; c.r++; // 0 to 1 origin

        int cnt = B[c.d][c.r];
        cnt -= B[c.d][c.l - 1];
        cnt -= B[c.u - 1][c.r];
        cnt += B[c.u - 1][c.l - 1];

        std::cout << ans + cnt << "\n";
    }

    return 0;
}
