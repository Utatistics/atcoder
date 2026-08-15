#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::set<int> s;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;

        s.insert(a);
    }

    ll ans = 0;

    int k = 0;
    while (s.size() > 1) {
        auto ir = s.lower_bound(k);
        auto il = ir != s.begin() ? std::prev(ir) : ir;

        int r = ir != s.end() ? *ir : *il;
        int l = *il;

        ll dr = std::abs(k - r);
        ll dl = std::abs(k - l);

        if (dl <= dr) {
            ans += dl;
            k = l;
            s.erase(l);
        }
        else {
            ans += dr;
            k = r;
            s.erase(r);
        }

    }
    ans += std::abs(k - *s.begin());

    std::cout << ans << std::endl;
    return 0;
}

