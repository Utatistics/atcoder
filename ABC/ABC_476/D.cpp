#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, M;
    ll K;
    std::cin >> N >> M >> K;

    ll X, Y;
    std::cin >> X >> Y;

    std::vector<ll> A(N), B(M);
    for (ll& a : A) std::cin >> a;
    for (ll& b : B) std::cin >> b;
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    std::vector<ll> psa(N + 1);
    for (int i = 0; i < N; ++i) {
        psa[i + 1] = psa[i] + A[i];
    }

    std::vector<ll> b0(M + 1);
    std::vector<ll> b1(M + 1);
    for (int i = 0; i < M; ++i) {
        b0[i + 1] = b0[i] + B[i]; // cost
        b1[i + 1] = b1[i] + (B[i] + K - 1) / K; // cnt
    }

    ll Z = X + Y * K;
    int ans = 0;
    for (int i = 0; i <= M; ++i) { // O(M * logN)
        if (b1[i] > Y) break;
        int j = std::upper_bound(psa.begin(), psa.end(), Z - b0[i]) - psa.begin() - 1;
        ans = std::max(ans, i + j);
    }
    std::cout << ans << '\n';
}
