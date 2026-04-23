#include <bits/stdc++.h>

using ll = long long;

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        std::string ans = "Yes";

        int N, H;
        std::cin >> N >> H;

        ll t0 = 0;
        ll l0 = H;
        ll u0 = H;

        for (int i = 0; i < N; i++) {    
            ll t1, l1, u1;
            std::cin >> t1 >> l1 >> u1;
            
            l0 = std::max(l0 - (t1 - t0), 0LL);
            u0 += t1 - t0;

            if (u0 < l1 || l0 > u1) ans = "No";
            if (ans == "No") continue; // still needs to read input

            t0 = t1;
            l0 = std::max(l0, l1);
            u0 = std::min(u0, u1);
        }

        std::cout << ans << "\n";
        
    }

    return 0;
}

