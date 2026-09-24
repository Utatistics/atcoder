#include <bits/stdc++.h>

using ll = long long;

int main() {
    ll sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;

    if ((sx + sy) % 2 != 0) --sx;
    if ((tx + ty) % 2 != 0) --tx;

    ll ans;
    ll x = std::abs(tx - sx), y = std::abs(ty - sy);
    if (x < y) ans = y;
    else ans = (x + y) / 2;
    std::cout << ans << std::endl;
    return 0;
}
