#include <bits/stdc++.h>

using ll = long long;

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        ll X, Y, K;
        std::cin >> X >> Y >> K;

        int ans = 0;
        while (X != Y) {
            if (X > Y) X /= K; else Y /= K;
            ++ans;
        } 
        std::cout << ans << "\n";
    }

    return 0;
}

