#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<int, int>;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<P> A(N);
    for (int i = 0; i < M; i++) std::cin >> A[i].first;
    for (int i = 0; i < M; i++) std::cin >> A[i].second;
    std::sort(A.begin(), A.end());
    A.emplace_back(N + 1, 1);

    ll ans = 0;

    int x0 = 0;
    ll num = 1;
    for (auto [x1, a] : A) {
        ll L = x1 - x0; // block length
        ll carry = num - L;
        ans += (L - 1) * L / 2;
        ans += L * carry;
        if (carry < 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
        x0 = x1;
        num = carry + a;
    }

    if (num != 1) std::cout << -1 << std::endl;
    else std::cout << ans << std::endl;

    return 0;
}

