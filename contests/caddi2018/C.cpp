#include <bits/stdc++.h>

using ll = long long;
using Pll = std::pair<ll, ll>;

int main () {
    ll N, P;
    std::cin >> N >> P;

    ll r = P;
    std::vector<Pll> prime;
    for (ll i = 2; i * i <= r; i++) {
        ll e = 0;
        while (r % i == 0) {
            e++;
            r /= i;
        }
        if (e > 0) prime.push_back({i, e});
    }
    if (r != 1LL) prime.push_back({r, 1});

    ll ans = 1;
    for (auto [p, e] : prime) {
        ll k = e / N;
        while (k--) ans *= p;
    }

    std::cout << ans << std::endl;
    return 0;
}
