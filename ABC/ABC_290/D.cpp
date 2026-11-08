#include <bits/stdc++.h>

using ll = long long;

void solve() {
    ll N, D, K;
    std::cin >> N >> D >> K;

    ll g = std::gcd(N, D);
    ll L = N / g;

    ll q = (K - 1) / L;
    ll r = (K - 1) % L;

    std::cout << (q + r * D) % N << '\n';
}

int main() {

    int T;
    std::cin >> T;

    while (T--) solve();
}
