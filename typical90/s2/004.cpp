#include<iostream>
#include<vector>

int main () {
    int H, W;
    std::cin >> H >> W;

    std::vector<int> sumH(H, 0), sumW(W, 0);
    std::vector<int> A(H * W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int a;
            std::cin >> a;
            A[i * W + j] = a;
            sumH[i] += a;
            sumW[j] += a;
        }
    }
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) std::cout << sumH[i] + sumW[j] - A[i * W + j] << " ";
        std::cout << "\n";
    }

    return 0;
}

