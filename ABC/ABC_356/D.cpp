#include <bits/stdc++.h>

using ll = long long;
static constexpr int MOD = 998244353;

int main() {
    ll N, M;
    std::cin >> N >> M;

    ll ans = 0;
    for (int i = 0; i < 60; i++) { // N < 2^60 (needs 2^0 - 2^59)
        if (!(M >> i & 1)) continue; // see ith bit of M
        ll p = 2ll << i; // cycle
        ll r = N % p; // residual

        ans += ((N - r) / 2);
        if (r >= (1ll << i)) { // r >= 2^k -> additional 1s
            ans += r - (1ll << i) + 1; // 
        }
        ans %= MOD;
    }

    std::cout << ans << std::endl;
    return 0;
}

