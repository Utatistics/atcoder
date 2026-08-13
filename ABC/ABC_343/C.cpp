#include <bits/stdc++.h>

using ll = long long;

int main() {
    ll N;
    std::cin >> N;

    auto solve = [&](const std::string& s) -> bool { // O(N) where N ~ 18
        bool res = true;

        int N = s.size();
        std::string t(s.rbegin(), s.rend());
        for (int i = 0; i < N; i++) {
            if (s[i] != t[i]) res = false;
        }
        return res;
    };

    ll ans = 0;
    for (int x = 1; 1LL * x * x * x <= N; x++) { // 1e6^3 ~ 1e18
        ll c = 1LL * x * x * x;
        std::string s = std::to_string(c);
        
        if (solve(s)) ans = c; // O(1)
    }

    std::cout << ans << std::endl;
    return 0;
}

