#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i]; // ~10^6

    std::vector<std::vector<P>> k(N / 2); // index
    std::vector<std::vector<char>> v(N / 2); // value
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            k[i].push_back({i, j});
            v[i].push_back(A[i][j]);
        }
        for (int j = i; j < N - i - 1; j++) {
            k[i].push_back({j, N - i - 1});
            v[i].push_back(A[j][N - i - 1]);
        }
        for (int j = N - i - 1; j > i; j--) {
            k[i].push_back({N - i - 1, j});
            v[i].push_back(A[N - i - 1][j]);
        }
        for (int j = N - i - 1; j > i; j--) {
            k[i].push_back({j, i});
            v[i].push_back(A[j][i]);
        }
    }

    std::vector<std::vector<char>> ans(N, std::vector<char>(N, '*'));
    for (int i = 0; i < N / 2; i++) {
        int M = k[i].size();
        int rs = (i + 1) % 4; // number of rotations
        int s = M / 4; // steps in a rotation
        for (int j = 0; j < M; j++) {
            auto [r, c] = k[i][j];
            int l = ((j + M) - s * rs) % M;
            ans[r][c] = v[i][l];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            std::cout << ans[i][j];
        std::cout << "\n";
    }

    return 0;
}
