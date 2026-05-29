#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    ll M;
    std::cin >> N >> M;

    ll s = 0;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        s += A[i];
    }
    if (M >= s) {
        std::cout << "infinite\n";
        return 0;
    }
    std::sort(A.begin(), A.end());
    std::vector<ll> ps(N + 1, 0);
    for (int i = 1; i <= N; i++) ps[i] = ps[i - 1] + A[i - 1];
    
    auto binary_search = [&](ll key) -> int {
        ll left = -1; // i = 0 does not always satisfy condition
        ll right = 1e14;
        while (right - left > 1) {
            ll mid = left + (right - left) / 2;
            auto it = std::lower_bound(A.begin(), A.end(), mid);
            ll t = ps[it - A.begin()] + mid * (A.end() - it);
            if (t > key) right = mid; // argmin k (key < A[k]) *ascending
            else left = mid;
        }
        return left;
    };

    int ans = binary_search(M);

    std::cout << ans << std::endl;
    return 0;
}
