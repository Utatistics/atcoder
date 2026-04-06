#include <bits/stdc++.h>

static const int N = 1e5;

std::vector<bool> sieveEratosthenes(int n) { // O(N log log N)
    std::vector<bool> isPrime(n + 1, true); // 1 origin, mark all as prime
    std::vector<int> minPrimeFactor(N + 1, -1); // the smallest prime divisor of i
    
    isPrime[1] = false;
    minPrimeFactor[1] = 1;

    for (int p = 2; p <= n; ++p) {
        if (!isPrime[p]) continue;
        minPrimeFactor[p] = p;

        for (int q = p * 2; q <= n; q += p) { // update as per p's multiples
            isPrime[q] = false; // q is not prime, a compsite of p
            if (minPrimeFactor[q] == -1) minPrimeFactor[q] = p; // p divides q
        }
    }
    return isPrime;
}


int main() {
    int Q;
    std::cin >> Q;

    std::vector<bool> isPrime = sieveEratosthenes(N + 1);
    
    std::vector<int> like2017(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            like2017[i] = like2017[i - 1];
        }
        else {
            like2017[i] = like2017[i - 1];
            if (isPrime[i] && isPrime[(i + 1) / 2]) like2017[i]++;
        }
    }

    while (Q--) {
        int l, r;
        std::cin >> l >> r; // 1 origin
        std::cout << like2017[r] - like2017[l - 1] << std::endl;
    }

    return 0;
}
