#include <bits/stdc++.h>

int main() {
    int N, V;
    std::cin >> N >> V;

    std::vector<int> W(N);
    for (int i = 0; i < N; i++) {
        std::cin >> W[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (i == j) continue;
                if (j == k) continue;
                if (k == i) continue;
                if (i + j + k + 3 > V) continue;
                
                ans = std::max(ans, W[i] + W[j] + W[k]);
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}

