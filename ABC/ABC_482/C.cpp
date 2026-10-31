#include <bits/stdc++.h>

using ll = long long;

int main() {
    int H, W, N, Q;
    std::cin >> H >> W >> N >> Q;

    std::map<int, ll> cnth, cntw;
    for (int i = 0; i < N; i++) {
        int r, c;
        std::cin >> r >> c;
        --r; --c;
        ++cnth[r]; ++cntw[c];
    }

    ll sh = 0, sw = 0;
    for (auto& [k, cnt] : cnth) {
        sh += cnt; cnt = sh;
    }
    for (auto& [k, cnt] : cntw) {
        sw += cnt; cnt = sw;
    }

    auto prefix = [&](const auto& m, int x) -> ll {
        auto it = m.upper_bound(x);

        if (it == m.begin()) return 0; // prev invalid
        else return std::prev(it)->second;
    };

    while (Q--) {
        int t;
        std::cin >> t;

        int a, b;
        std::cin >> a >> b;
        --a; --b;

        ll ans;
        if (t == 1) ans = prefix(cnth, b) - prefix(cnth, a - 1);
        else ans = prefix(cntw, b) - prefix(cntw, a - 1);
    
        std::cout << ans << '\n';
    }

    return 0;
}
