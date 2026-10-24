#include <bits/stdc++.h>

using ll = long long;
static const ll INF = 1LL<<60;

int main() {
    ll N, M;
    std::cin >> N >> M;

    auto ceil = [&](ll x, ll k) -> ll {
        return (x + k - 1) / k;
    };

    ll ans = INF;

    for (ll a = 1; a <= N; a++) {
        ll b = ceil(M, a);

        if (b <= N) {
            ans = std::min(ans, a * b);
        }
        
        if (a * a > M) break;
    }

    if (ans == INF) std::cout << -1 << std::endl;
    else std::cout << ans << std::endl;

    return 0;
}

