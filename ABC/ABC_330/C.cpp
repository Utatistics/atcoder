#include <bits/stdc++.h>

using ll = long long;
static constexpr ll INF = 2 * 1e12;

int main() {
    ll D;
    std::cin >> D;

    ll ans = INF;
    for (int x = 0; 1LL * x * x <= D; x++) {
        ll R = D - 1LL * x * x;
        ll y = std::sqrt(R);

        ans = std::min(ans, std::abs(y * y - R));
        ++y;
        ans = std::min(ans, std::abs(y * y - R));
    }

    std::cout << ans << std::endl;
    return 0;
}

