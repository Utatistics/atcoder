#include <bits/stdc++.h>

using ll = long long;

static const int M = 1e6 + 1;

int main() {
    ll N;
    std::cin >> N;

    std::vector<bool> isPrime(M, true); // mark all as prime
    auto sieveEratosthenes = [&](int n) -> void {

        isPrime[0] = false;
        isPrime[1] = false;

        for (int p = 2; p * p <= n; ++p) {
            if (!isPrime[p]) continue;
            for (int q = p * p; q <= n; q += p) {
                isPrime[q] = false;
            }
        }
    };
    sieveEratosthenes(M);

    std::vector<ll> cnt(M, 0);
    for (int i = 1; i < M; i++) cnt[i] = cnt[i - 1] + isPrime[i];

    ll ans = 0;
    for (ll a = 0; a * a * a * a * a <= N; a++) { // a < N^{1/5} ~ 10^{2.4}
        if (!isPrime[a]) continue;
        for (ll b = a + 1; b * b * b <= N; b++) { // b < N^{1/3} ~ 10^4
            if (!isPrime[b]) continue;

            ll cmax = std::sqrt(N / a / a / b); // c <= √N/(a^2 * b)
            if (b < cmax) { // only count c, not a & b
                ans += cnt[cmax] - cnt[b];
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
