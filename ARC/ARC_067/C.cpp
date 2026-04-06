#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<ll , ll>;

static const int MOD = 1e9 + 7;

int main() {
    // input
    int N;
    std::cin >> N;

    // solve
    std::map<int , int> m;
    for (int i = N; i > 1; i--) {
        ll r = i; // remainder
        
        for (ll p = 2; p * p <= r; p++) { // exlude 1 and N itself.
            if (r % p != 0) continue;
            while (r % p == 0) {
                m[p]++;
                r /= p;
            }
        }
        if (r != 1LL) m[r]++;
    }

    // presentation
    ll ans = 1;
    for (auto p : m) {
        ans = (1LL * ans * (p.second + 1)) % MOD;
    }
    std::cout << ans << std::endl;

    return 0;
}

