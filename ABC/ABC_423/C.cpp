#include <bits/stdc++.h>

int main() {
    // input processing
    int N, R;
    std::cin >> N >> R;

    std::vector<int> L(N);
    for (int i = 0; i < N; i++) std::cin >> L[i];

    // solve
    int l = 0;
    int r = N - 1;
    for (int i = 0; i < N; i++) {
        if (L[i] == 0) {
            l = std::min(i, R + 1);
            break;
        }

    }
    for (int i = N - 1; i >= 0; i--) {
        if (L[i] == 0) {
            r = std::max(i, R - 1);
            break;
        } 
    }

    int ans = 0;
    for (int i = l; i <= r; i++) {
        ans += (L[i] == 0) ? 1 : 2;
    }

    // presentation
    std::cout << ans << std::endl;
    
    return 0;    
}

