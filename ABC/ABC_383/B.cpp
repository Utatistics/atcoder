#include <bits/stdc++.h>

using P = std::pair<int, int>;

int H, W, D;
std::vector<std::vector<char>> S;

int manDist(int i, int j, int id, int jd) {
    return std::abs(i - id) + std::abs(j - jd);
}

int main() {
    // input
    std::cin >> H >> W >> D;

    S.resize(H, std::vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> S[i][j];
        }
    }

    // collect floor cells
    std::vector<P> A;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.') A.push_back({i,j});
        }
    }

    int ans = 0;
    int N = A.size();
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int cnt = 0;
            for (auto [x, y] : A) {
                if (manDist(x, y, A[i].first, A[i].second) <= D || // 1st
                    manDist(x, y, A[j].first, A[j].second) <= D) { // 2nd
                    cnt++;
                }
            }
            ans = std::max(ans, cnt);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
