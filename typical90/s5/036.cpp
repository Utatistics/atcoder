#include <bits/stdc++.h>

using ll = long long;
using P =  std::pair<ll, ll>;

static const int INF = 1e9;

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<P> p;
    ll xmax = -INF, ymax = -INF;
    ll xmin = INF, ymin = INF;

    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;

        ll nx = x + y; // x' = x + y / √2
        ll ny = y - x; // y' = y - x / √2

        p.emplace_back(nx, ny);

        xmax = std::max(xmax, nx);
        ymax = std::max(ymax, ny);
        xmin = std::min(xmin, nx);
        ymin = std::min(ymin, ny);
    }

    while (Q--) {
        int q;
        std::cin >> q;
        --q;

        auto [x, y] = p[q];

        ll ans = std::max({
                std::abs(x - xmax),
                std::abs(x - xmin),
                std::abs(y - ymax),
                std::abs(y - ymin)
                });

        std::cout << ans << "\n";
    }

    return 0;
}
