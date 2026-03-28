#include <bits/stdc++.h>

int main() {
    int X, Y;
    std::cin >> X >> Y;

    int ans = (X + Y > 12) ? X + Y - 12 : X + Y;
    std::cout << ans << std::endl;

    return 0;
}

