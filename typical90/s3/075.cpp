#include <bits/stdc++.h>

using ll = long long;

int main() {
    ll N;
    std::cin >> N;

    ll r = N; // remainder
    std::vector<ll> p; // prime rumbers
    for (ll i = 2; i * i <= N; i++) {
        while (r % i == 0) {
            r /= i;
            p.push_back(i);
        }
    }
    if (r != 1LL) p.push_back(r);

    // presentation
    ll k = p.size();
    ll x = 1;
    ll ans = 0;
    while (x < k) {
        x *= 2;
        ans ++;
    }
    std::cout << ans << std::endl;

    return 0;
}

