#include <bits/stdc++.h>

using ll = long long;

int main() {
    ll N;
    std::cin >> N;

    ll ans = 0;
    for (int a = 1; a < 60; a++) {
        ll x = N;
        for (int i = 0; i < a; i++) {
            x /= 2;
        }
        ll m = sqrtl(x);
        ans += (m  + 1) / 2;
    }

    std::cout << ans << std::endl;
    return 0;
}

