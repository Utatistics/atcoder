#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, M;
    ll D;
    std::cin >> N >> M >> D;

    std::vector<ll> A(N), B(M);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < M; i++) std::cin >> B[i];

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    auto binarySearch = [&](ll i) -> int {
        int l = -1;
        int r = M;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if (B[mid] > A[i] + D) r = mid;
            else l = mid;
        }

        return l;
    };

    ll ans = -1;

    for (int i = 0; i < N; i++) {
        int j = binarySearch(i);
        if (j != -1 && A[i] - D <= B[j]) { // A[i] - D <= B[j] <= A[i] + D
            ans = std::max(ans, A[i] + B[j]);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
