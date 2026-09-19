#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    int L = S.size();
    int N = 1;
    for (int i = 0; i < L; i++) N *= 10;

    auto sieveEratosthenes = [&](int n) {
        std::vector<bool> isPrime(n, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for (int p = 2; p * p < n; ++p) {
            if (!isPrime[p]) continue;
            for (int q = p * p; q < n; q += p) {
                isPrime[q] = false;
            }
        }
        return isPrime;
    };
    auto ps = sieveEratosthenes(N);

    auto f = [&](int p) -> bool {
        std::vector<int> m(10, -1); // int2
        std::vector<int> inv(26, -1);

        for (int i = L - 1; i >= 0; --i) {
            int c = S[i] - 'a';
            int d = p % 10;
            p /= 10;
            
            if (m[d] != -1 && m[d] != c) return false;
            if (inv[c] != -1 && inv[c] != d) return false;
            
            m[d] = c;
            inv[c] = d;
        }
        return true;
    };

    for (int p = N / 10; p < N; ++p) { // N not included
        if (!ps[p]) continue;

        if (f(p)) {
            std::cout << p << '\n';
            return 0;
        }
    }

    std::cout << -1 << '\n';
}
