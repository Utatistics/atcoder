#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, M, P;
    std::cin >> N >> M >> P;

    std::vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < M; i++) std::cin >> B[i];
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    std::vector<ll> ps(M + 1, 0);
    for (int i = 1; i <= M; i++) ps[i] = ps[i - 1] + B[i - 1];

    auto binarySearch = [&](int a) -> int {
        int l = -1;
        int r = M;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (a + B[mid] > P) r = mid;
            else l = mid;
        }
        return r;
    };

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int k = binarySearch(A[i]);
        ans += 1LL * k * A[i] + ps[k];
        ans += 1LL * P * (M - k);
    }

    std::cout << ans << std::endl;
    return 0;
}
