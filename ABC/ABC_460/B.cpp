#include <bits/stdc++.h>

using ll = long long;

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        ll x1, y1, r1, x2, y2, r2;
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        ll x = std::abs(x1 - x2);
        ll y = std::abs(y1 - y2);

        ll d = (x * x) + (y * y);
        ll r = (r1 + r2) * (r1 + r2);
        ll diff = std::abs(r1 - r2);

        if (d < diff * diff) // one circle strictly inside the other
            std::cout << "No\n";
        else if (d > r) // circles are too far apart
            std::cout << "No\n";
        else // tangent or intersecting
            std::cout << "Yes\n";
    }

    return 0;
}
