#include <bits/stdc++.h>

using ll = long long;

int solve(int x) {
    std::string s = std::to_string(x);
    std::reverse(s.begin(), s.end());
    
    return std::stoll(s);
}

int main() {
    // input processing
    int X, Y;
    std::cin >> X >> Y;

    // solve
    ll ans = 0;
    ll a = X;
    ll b = Y;

    for (int i = 2; i < 10; i++) {
        ans = solve(a + b);
        a = b;
        b = ans;

        // debug
        // std::cout << ans << std::endl;
    }

    // presentation
    std::cout << ans << std::endl;
    
    return 0;
}
