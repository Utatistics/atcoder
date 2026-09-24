#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    ll T;
    std::cin >> N >> T;

    std::string S;
    std::cin >> S;

    std::vector<ll> L;
    std::vector<ll> R;

    for (int i = 0; i < N; ++i) {
        ll x;
        std::cin >> x;

        if (S[i] == '0') L.push_back(x);
        else R.push_back(x);
    }
    std::sort(L.begin(), L.end());

    ll ans = 0;
    for (ll r : R) { // r < l && l - r < 2T => r < l < r + 2T
        auto first = std::upper_bound(L.begin(), L.end(), r);
        auto last = std::upper_bound(L.begin(), L.end(), r + 2 * T);

        ans += last - first;
    }

    std::cout << ans << '\n';

    return 0;
}
