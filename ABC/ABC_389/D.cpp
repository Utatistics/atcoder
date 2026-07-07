#include <bits/stdc++.h>

using ll = long long;

int main() {
    int R;
    std::cin >> R;

    auto f = [&](ll x, ll y) -> bool {
        return 2LL * (x * x + y * y + x + y) + 1LL > 2LL * R * R;
    };

    auto binarySearch = [&](int x) -> int {
        int l = -1;
        int r = R;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (f(x, mid)) r = mid;
            else l = mid; // in circle
        }
        return l;
    };

    ll ans = 0;
    int len = 0;
    for (int i = 0; i < R; i++) {
        int j = binarySearch(i);
        if (i == 0) len = j + 1;
        ans += j + 1; // 0 index
    }

    ans = 4 * ans - 4 * len + 1;
    std::cout << ans << std::endl;
    return 0;
}
