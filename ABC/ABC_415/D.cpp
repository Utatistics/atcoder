#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<ll, ll>;

int main() {
    ll N;
    int M;
    std::cin >> N >> M;

    std::vector<P> v;
    for (int i = 0; i < M; i++) {
        ll a, b;
        std::cin >> a >> b;
        v.push_back({a, a - b}); // (a, diff)
    }

    sort(v.begin(), v.end(), [](auto &l, auto &r){
        if (l.second != r.second) return l.second < r.second;
        return l.first < r.first;
    });

    ll x = N;
    ll ans = 0;
    for (auto [a, d] : v) { // {a, diff}}
        if (x < a) continue;
        ll k = (x - a) / d + 1;
        ans += k;
        x -= k * d;
    }

    std::cout << ans << std::endl;
    return 0;
}
