#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> cnt(N + 1, 0);     
    auto sieveeratosthenes = [&]() -> void { // identify primes up to n

        cnt[0] = 1;
        cnt[1] = 1;
        
        for (int p = 2; p <= N; ++p) { // O(N)
            if (cnt[p] != 0) continue;
            for (int q = p; q <= N; q += p) { // O(log logN)
                cnt[q]++;
            }
        }
    };
    sieveeratosthenes(); // O(N log log N)
    
    ll ans = 0;
    for (int i = 2; i <= N; i++) {
        if (cnt[i] >= K) ++ans;
    }

    std::cout << ans << std::endl;
    return 0;
}


