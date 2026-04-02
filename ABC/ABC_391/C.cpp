#include <bits/stdc++.h>

int main() {
    // input
    int N, Q;
    std::cin >> N >> Q;

    int ans = 0;
    std::vector<int> P(N);
    std::vector<int> H(N, 1);
    for (int i = 0; i < N; i++) P[i] = i;
    
    while (Q--) {
        int t;
        std::cin >> t;

        // solve
        if (t == 1) {
            int p, h;
            std::cin >> p >> h;
            p--; h--;
            
            int i = P[p]; // p is in h[i], to be removed

            if (H[h] == 1) ans++;
            if (H[i] == 2) ans--;

            // move
            P[p] = h;
            H[i]--;
            H[h]++;
        }

        // presentation
        if (t == 2) std::cout << ans << std::endl;    
    }
    
    return 0;
}
