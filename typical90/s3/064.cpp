#include <bits/stdc++.h>

using ll = long long;

int main () {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<ll> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    ll ans = 0;
    std::vector<ll> d(N, 0); // d[0] unused
    for (int i = 1; i < N; i++) {
        d[i] = A[i] - A[i - 1];
        ans += std::abs(d[i]);
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        ll v;
        std::cin >> l >> r >> v;
        l--; r--;

        if (l > 0) {
            ll prev = d[l];
            d[l] += v;
            ans += std::abs(d[l]) - std::abs(prev);
        }

        if (r < N - 1) {
            ll prev = d[r + 1];
            d[r + 1] -= v;
            ans += std::abs(d[r + 1]) - std::abs(prev);
        }

        std::cout << ans << "\n";
    }

    return 0;
}

