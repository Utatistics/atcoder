#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<ll, ll>;

int main() {
    ll L, R;
    std::cin >> L >> R;

    auto pow = [&](int k) -> ll {
        ll res = 1;
        for (int i = 0; i < k; i++) res *= 2;
        return res;
    };

    auto solve = [&](ll l, int i) -> bool {
        ll p = pow(i);

        if (l % p != 0) return false; // must be divisible by 2^i 
        if (l + p > R) return false; // window too big 
        return true;
    };

    auto binary_search = [&](ll l) {
        int left = 0;
        int right = 61;

        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (solve(l, mid)) left = mid;
            else right = mid;
        }
        return left;
    };

    std::vector<P> ans;
    ll l = L;
    ll r = 0;

    while (l < R) {
        int i = binary_search(l);
        ll p = pow(i);
        ll j = l / p;

        r = p * (j + 1);
        ans.push_back({l, r});
        l = r;
    }

    std::cout << ans.size() << "\n";
    for (auto [l, r] : ans) 
        std::cout << l << " " << r << "\n";

    return 0;
}
