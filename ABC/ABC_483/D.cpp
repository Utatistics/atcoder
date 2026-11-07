#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<ll> P(N + 1, 0);

    for (int i = 0; i < N; i++) {
        P[i + 1] = P[i] + A[i];
    }

    ll ans = 0;

    for (int i = 0; i < N; i++) {

    }

    std::cout << ans + 1 << '\n';

    return 0;
}

