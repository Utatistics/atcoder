#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, S;
    ll L;
    std::cin >> N >> S >> L;
    --S;

    std::vector<int> A(N - 1);
    for (int i = 0; i < N - 1; i++) {
        std::cin >> A[i];
    }

    std::vector<ll> ps(N, 0);
    for (int i = 1; i < N; i++) {
        ps[i] = ps[i - 1] + A[i - 1];
    }

    int ans = 1;

    for (int l = 0; l <= S; l++) {
        for (int r = S; r < N; r++) {
            ll left = ps[S] - ps[l];
            ll right = ps[r] - ps[S];
            ll t = ps[r] - ps[l];

            ll c = t + std::min(left, right);

            if (c <= L) ans = std::max(ans, r - l + 1);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
