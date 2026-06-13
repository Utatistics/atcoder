#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<ll> A(N);
    ll max = 0;
    ll min = 1e12 + 9;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        max = std::max(max, A[i]);
        min = std::min(min, A[i]);
    }
    std::sort(A.begin(), A.end());

    std::vector<ll> B(N - 1, 0);
    for (int i = 0; i < N - 1; i++) 
        B[i] = A[i + 1] - A[i];
    std::sort(B.begin(), B.end()); // asceinding
    
    ll ans = max - min;
    for (int i = N - 2; i > N - M - 1; i--) {
        ans -= B[i];
    }

    std::cout << ans << std::endl;
    
    return 0;
}

