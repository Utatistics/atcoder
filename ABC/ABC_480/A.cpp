#include <bits/stdc++.h>

int N = 2;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
bool isBound(int i , int j) { return (0 <= i && i < N && 0 <= j && j < N);}

int main() {
    std::vector<std::string> G(N);
    for (int i = 0; i < N; i++) std::cin >> G[i];

    bool ans = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (G[i][j] == 'A') {
                for (int k = 0; k < 4; k++) {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if (!isBound(ni, nj)) continue;
                    if (G[ni][nj] == 'D') {
                        ans = true;
                    }
                }
            }
        }
    }
    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

