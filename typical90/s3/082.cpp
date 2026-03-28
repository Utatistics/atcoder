#include <bits/stdc++.h>

using ll = long long;
static const int MOD = 1e9 + 7;

int dcnt(ll x) { return std::to_string(x).size();}

int main() {
    ll L, R; // changed int → ll to handle large input
    std::cin >> L >> R;

    ll ans = 0;
    // instead of looping through every number, loop by digit length
    for (int d = 1; d <= 18; d++) {
        ll start = std::max(L, (ll)std::pow(10, d-1));
        ll end = std::min(R, (ll)std::pow(10, d) - 1);
        if (start > end) continue;
        ll cnt = end - start + 1;
        ll sum = (start % MOD + end % MOD) * (cnt % MOD) % MOD * ((MOD + 1) / 2) % MOD; // sum formula
        ans = (ans + sum * d % MOD) % MOD;
    }

    std::cout << ans << std::endl;
    return 0;
}
