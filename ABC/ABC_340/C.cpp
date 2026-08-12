#include <bits/stdc++.h>

using ll = long long;

int main() {
    ll N;
    std::cin >> N;

    std::map<ll, ll> m;
    auto f = [&](auto f, ll n) -> ll {
        if (n == 1) return 0LL;
        if (m.count(n) > 0) return m[n];

        ll a = n / 2, b = (n + 1) / 2;
        m[n] = n + f(f, a) + f(f, b);
        return m[n];

    };

    std::cout << f(f, N) << std::endl;
    return 0;
}

