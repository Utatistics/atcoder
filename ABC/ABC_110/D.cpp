#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<ll, ll>;
static const int MOD = 1e9 + 7;
static const int MAX = 510000;

std::vector<ll> fac(MAX);
std::vector<ll> finv(MAX);
std::vector<ll> inv(MAX);

void COMinit() { // prepare table
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll binomialCoefficinet(int n, int k){ // binomical coefficient % MOD
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    // solve
    ll r = M; // remainder
    std::vector<P> pf; // prime factors
    for (ll p = 2; p * p <= r; p++) { // If r has a factor, at least one of them must be ≤ √r
        int cnt = 0;
        while (r % p == 0) { r /= p; cnt++; }
        pf.push_back({p, cnt});
    }
    if (r != 1LL) pf.push_back({r, 1});

    ll ans = 1;
    COMinit();
    for (auto [p, k] : pf) {
        ll bc = binomialCoefficinet(N + k - 1, k); // nHk = n+k-1Ck
        ans = (ans * bc) % MOD;
    }

    std::cout << ans << std::endl;
    return 0;
}

