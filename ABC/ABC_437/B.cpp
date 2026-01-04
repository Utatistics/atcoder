#include <bits/stdc++.h>

int main() {
    // input processing
    int H, W, N;
    std::cin >> H >> W >> N;

    std::vector<int> A(H * W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> A[j + i*W];        
        }
    }

    std::vector<int> B(N);
    for (int i = 0; i < N; i++) std::cin >> B[i];


    // solve
    int ans = 0;
    for (int i = 0; i < H; i++) {
        int cnt = 0;
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < N; k++) {
                cnt += (B[k] == A[j + i*W]) ? 1 : 0;
            }
            ans = std::max(ans, cnt);
        }
    }

    // presentation
    std::cout << ans << std::endl;

    return 0;
}

