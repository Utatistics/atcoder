#include <bits/stdc++.h>

using ll = long long;
static constexpr int MOD = 998244353;

ll modpow(ll a, ll n) { // a ^ n mod MOD
    ll x = 1;

    while (n > 0) {
        if (n & 1) x = x * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return x;
}

int main() {
    ll N;
    std::cin >> N;

    std::string s = std::to_string(N);
    int d = (int)s.size();

    // Vn = N (M^N - 1)(M - 1)^{-1} (mod MOD), where M = 10^d. (M - 1)^{-1} is 逆元 of (M - 1)
    ll M = 1;
    for (int i = 0; i < d; i++) M = M * 10 % MOD;

    ll num = modpow(M, N) - 1; // M^N - 1
    if (num < 0) num += MOD; // num can be -1 here
    ll inv = modpow(M - 1, MOD - 2); // fermet (M - 1)^{-1} mod MOD -> (M - 1)^{MOD - 2} mod MOD

    ll ans = (num * inv % MOD) * (N % MOD) % MOD;
    std::cout << ans << std::endl;

    return 0;
}
