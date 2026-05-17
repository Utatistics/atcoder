#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<ll, int>;

int main() {
    int N, C;
    ll M;
    std::cin >> N >> M >> C;

    std::map<ll, int> m; // {loc, cnt}
    for (int i = 0; i < N; i++) {
        ll a;
        std::cin >> a;
        m[a]++;
    }
    int n = m.size();

    std::vector<P> A;
    for (auto [k, v] : m) A.push_back({k, v});
    for (auto [k, v] : m) A.push_back({k + M, v});

    ll ans = 0;
    ll pk = A[n - 1].first - M;
    int r = 0, c = 0;
    for (int l = 0; l < n; l++) {
        while (c < C) {
            c += A[r].second;
            r++;
        }
        // l moving forward
        auto [k, v] = A[l];
        ans += 1LL * (k - pk) * c;
        pk = k;
        c -= v;
    }

    std::cout << ans << std::endl;

    return 0;
}
