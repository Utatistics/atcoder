#include <bits/stdc++.h>

int H, W;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};

bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

bool isCorner(int i , int j) {
    bool res = false;
    for (int k = 0; k < 4; k++) { // grid search
        int id = i + di[k];
        int jd = j + dj[k];
        if (!isBound(id, jd)) res = true;
    }

    return res;
}

int main() {
    std::cin >> H >> W;

    std::vector<std::vector<char>> A(H, std::vector<char>(W, '.'));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (isCorner(i, j)) A[i][j] = '#';
            std::cout << A[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
