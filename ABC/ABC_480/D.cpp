#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    
    std::vector<ll> ps(N + 1, 0);
    std::vector<ll> pps(N + 1, 0);
    std::vector<ll> K(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        ps[i] = ps[i - 1] + A[i - 1]; // cumsum
        pps[i] = pps[i - 1] + ps[i]; // nested cumsum
        K[i] = 1LL * i * (i + 1) / 2;
    }
     
    auto f = [&](ll x) -> ll {
        if (x == 0) {
            return 0;
        }

        int k = std::lower_bound(K.begin(), K.end(), x) - K.begin();
        int i = x - (1LL * k * (k - 1) / 2); // offset
        return pps[k - 1] + ps[i];
    };

    while (Q--) {
        ll L, R;
        std::cin >> L >> R;

        std::cout << f(R) - f(L - 1) << "\n";
    }
    return 0;
}
