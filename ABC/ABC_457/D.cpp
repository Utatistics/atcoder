#include <bits/stdc++.h>

using ll = long long;
static const ll MAX = 2LL * (ll)1e18 + 1;

template<class F>
ll binary_search(F f) {
    ll left = -1;
    ll right = MAX;
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        if (f(mid)) right = mid;
        else left = mid;
    }
    return left; // largest
}

int main() {
    int N;
    ll K;
    std::cin >> N >> K;

    std::vector<ll> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    auto solve = [&](ll k) -> bool {
        ll cnt = 0;
        for (int i = 0; i < N; i++) {
            if (k <= A[i]) continue; // no ops needed, avoid negative div
            ll d = k - A[i];
            cnt += (d + i) / (i + 1); // ceil(a / b) = (a + b - 1) / b
            if (K < cnt) return true;
        }
        return false;
    };

    ll ans = binary_search(solve);
    std::cout << ans << std::endl;
    return 0;
}
