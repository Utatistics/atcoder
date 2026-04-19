#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<ll, ll>;

int main() {
    int N, X, Y;
    std::cin >> N >> X >> Y;

    std::vector<P> A;
    for (int i = 0; i < N; i++) {
        ll a;
        std::cin >> a;
        A.push_back({a, 1LL * a * Y});
    }
    std::sort(A.begin(), A.end()); // O(NlogN)

    ll ans = A[0].first;
    for (int i = 1; i < N; i++) {
        auto [ai, ay] = A[i];
        ll diff = ay - A[0].second;
        if (diff % (Y - X) == 0 && diff / (Y - X) <= ai) {
            ans += ai - (diff / (Y - X));
        }
        else {
            ans = -1;
            break;
        }
    }
    
    std::cout << ans << std::endl;

    return 0;
}
