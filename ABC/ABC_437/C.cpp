#include <bits/stdc++.h>

using ll = long long;

int main() {
    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        // input processing
        int N;
        std::cin >> N;

        ll P = 0; // sum of powers
        std::vector<ll> wp(N); // w + p for ith deer 
        for (int i = 0; i < N; i++) {
            int w, p;
            std::cin >> w >> p;
            P += p;
            wp[i] = w + p;
        }
        
        std::sort(wp.begin(), wp.end()); // O(N * logN), ascending
        
        // solve
        int i = 0; int cnt = 0;
        ll s = 0; // cumsum of (w + p)
        while ((s += wp[i]) <= P) {
            cnt++;
            i++;
        }

        // presentation
        std::cout << cnt << "\n";

    }

    return 0;
}

