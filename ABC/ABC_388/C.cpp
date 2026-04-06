#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<ll> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    ll ans = 0;
    int j = 0;
    for (int i = 0; i < N; i++) {
        while (A[i] * 2LL > A[j] && j < N) { j++; }
        ans += N - j;
    }

    std::cout << ans << std::endl;
    return 0;
}
