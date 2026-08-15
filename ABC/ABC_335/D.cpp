#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> ans(N, std::vector<int>(N, -1));
    int cnt = 1;
    for (int i = 0; i < N / 2; i++) {
        for (int r = i; r < N - 1 - i; r++)
            ans[i][r] = cnt++;
        for (int d = i; d < N - 1 - i; d++)
            ans[d][N - 1 - i] = cnt++;
        for (int l = N - 1 - i; l > i; l--)
            ans[N - 1 - i][l] = cnt++;
        for (int u = N - 1 - i; u > i ; u--)
            ans[u][i] = cnt++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ans[i][j] > 0) std::cout << ans[i][j] << " "; 
            else std::cout << "T" << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

