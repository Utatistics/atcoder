#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main () {
    // input
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<int>> A(H, std::vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }

    // solve
    int ans = 0;
    for (int i = 0; i < (1 << H); i++) { // a selectoin of row, O(2^H) 
        std::map<int, int> m; // {v, cnt}
        for (int k = 0; k < W; k++) { // a column, O(W)
            bool status = true;
            int p = -1;
            for (int j = 0; j < H; j++) { // check each of selected rows
                if (i & (1 << j)) {
                    if (p == -1) p = A[j][k]; // pick the first selected row's value
                    else if (A[j][k] != p) {
                        status = false;
                        break;
                    }
                }
            }
            if (status && p != -1) {
                m[p]++; // increment count for this value
            }
        }

        // find the max column count for this subset of rows
        for (auto [v, cnt] : m) ans = std::max(ans, cnt * __builtin_popcount(i)); // O(W)

    }

    // presentation
    std::cout << ans << std::endl;

    return 0;
}
