#include <bits/stdc++.h>

int main() {
    // input
    int N;
    std::cin >> N;
    int c = N;

    std::vector<int> H(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        std::cin >> H[i];
        if (H[i] == 0) c--;
    }

    // solve
    int ans = 0;
    while (c) {
        int flg = 0;
        for (int i = 0; i <= N; i++) {
            if (flg == 0 && H[i] != 0) {
                flg = 1;
                ans++;
            }
            else if (flg == 1 && H[i] == 0) {
                flg = 0;
            }

            if (i > 0 && H[i] > 0) {
                H[i]--;
                if (H[i] == 0) c--;
            }
        }
    }
    
    // presentation
    std::cout << ans << std::endl;
    return 0;
}

