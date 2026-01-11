#include <bits/stdc++.h>

using ll = long long;

int mod(int a, int b) {return (a % b + b) % b;}

int main() {
    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        // input processing
        int N, W;
        std::cin >> N >> W;
        
        std::vector<int> C(N);
        for (int i = 0; i < N; i++)
            std::cin >> C[i];

        // solve
        std::vector<ll> cpm(2 * W); // cost per mod
        for (int i = 1; i <= N; i++) 
            cpm[mod(i, 2 * W)] += C[i - 1];

        ll ans = 0; // init at 'x = 0'
        for (int i = 1; i <= N; i++) 
            ans += (mod(i, 2 * W) < W) ? C[i  - 1] : 0;
  
        ll tmp = ans;
        int p = 0; int q = W;
        for (int x = 1; x <= 2 * W; x++) { // x not needed
            p = (p > 0) ? p - 1 : 2 * W - 1;
            q = (q > 0) ? q - 1 : 2 * W - 1;
            tmp += cpm[p] - cpm[q];
            ans = std::min(ans, tmp);
        }

        std::cout << ans << "\n";
        
    }

    return 0;
}

