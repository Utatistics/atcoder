#include <bits/stdc++.h>

using ll = long long;

static constexpr int MOD = 998244353;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(M);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < M; i++) std::cin >> B[i];

    std::sort(B.begin(), B.end());

    std::vector<ll> ps(M + 1, 0);
    for (int i = 1; i <= M; i++) ps[i] = ps[i - 1] + B[i - 1];

    auto binarySearch = [&](int key) -> int {
        int left = -1;
        int right = M;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (B[mid] > key) right = mid;
            else left = mid;
        }
        return right;
    };

    auto mod = [&](ll a, int b) {return (a % b + b) % b;};
    
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int a = A[i];
        int j = binarySearch(a);

        ll aj = 1LL * a * j;
        ans += mod(aj -  ps[j], MOD);
        ans %= MOD;

        ll pj = ps[M] - ps[j];
        ll bj = 1LL * a * (M - j);
        ans += mod(pj - bj, MOD);
        ans %= MOD;
    }

    std::cout << ans % MOD << std::endl;
    return 0;
}
