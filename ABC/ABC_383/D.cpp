#include <bits/stdc++.h>

using ll = long long;

int main() {
    ll N;
    std::cin >> N;

    std::vector<int> primes;
    auto sieveEratosthenes = [&](int n) {
        std::vector<bool> isPrime(n + 1, true);
        std::vector<int> minPrimeFactor(n + 1, -1);

        isPrime[0] = false;
        isPrime[1] = false;
        minPrimeFactor[1] = 1;

        for (int p = 2; p <= n; ++p) {
            if (!isPrime[p]) continue;
            minPrimeFactor[p] = p;

            for (int q = p * 2; q <= n; q += p) {
                isPrime[q] = false;
                if (minPrimeFactor[q] == -1) {
                    minPrimeFactor[q] = p;
                }
            }
        }

        for (int i = 2; i <= n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
    };

    ll ans = 0;

    sieveEratosthenes(1e6);
    for (int p : primes) { // p^8
        ll x = 1;
        for (int i = 0; i < 8; ++i) {
            x *= p;
        }
        if (x > N) break;
        ++ans;
    }
    int M = primes.size();
    for (int i = 1; i < M; ++i) { // p^2 * q^2 (p > q)
        for (int j = 0; j < i; ++j) {
            ll x = 1LL * primes[i] * primes[i] * primes[j] * primes[j];
            if (x > N) break;
            ++ans;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
