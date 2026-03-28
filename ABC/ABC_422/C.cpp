#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input processing
    int T;
    std::cin >> T;

    // solve
    for (int i = 0; i < T; i++) {
        int na, nb, nc;
        std::cin >> na >> nb >> nc;
        ll ans = std::min((nb + std::max(na, nc)) / 2, std::min(na, nc));
        ll ans = std::min({na, nc, (na + nb + nc) / 3});
        
        // presentation
        std::cout << ans << std::endl;
    }

    return 0;
}

