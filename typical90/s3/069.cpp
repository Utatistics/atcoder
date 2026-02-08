#include <bits/stdc++.h>

using ll = long long;
static const int MOD = 1e9 + 7;

ll expBySquare(ll k, ll n, int mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * k % mod;
        k = k * k % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    // input processing
    ll N, K;
    std::cin >> N >> K;

    // solve
    ll ans;
    if (N == 1) ans = K;   // ← fixed
    else {
        ans = 1LL;
        ll K2 = expBySquare(K - 2, N - 2, MOD);

        ans = (ans * K) % MOD;
        ans = (ans * (K - 1)) % MOD;
        ans = (ans * (K2)) % MOD;
    }

    // presentation
    std::cout << ans << std::endl;

    return 0;
}

