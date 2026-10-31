#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    auto solve = [&](int x) -> ll { // O(√N)
        ll res = 0;

        for (int j = 1; 1LL * j * j <= x; j++) {
            if (x % j == 0) {
                res += 1LL * j * j == x ? 1 : 2;
            }
        }
        return res;
    };

    ll ans = 0;

    for (int i = 1; i < N; i++) { // O(N * √N)
        ans += solve(i) * solve(N - i);
    }

    std::cout << ans << '\n';

    return 0;
}
