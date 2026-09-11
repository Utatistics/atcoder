#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::map<ll, ll> m;
    for (int i = 0; i < N; i++) {
        int s, c;
        std::cin >> s >> c;
        m[s] = c;
    }

    for (auto [s, c] : m) {
        m[s] = c % 2;
        m[2 * s] += c / 2;
    }

    ll ans = 0;
    for (auto p : m) ans += p.second;
    
    std::cout << ans << std::endl;
    return 0;
}

