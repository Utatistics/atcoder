#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input processing
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> C(N, 0); // counter
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        C[A[i] - 1]++;
    }

    // solve
    int c = 0;
    for (int i = 0; i < N; i++) c += C[i];
    
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (C[i] >= 2) {
            ll b = 1LL * C[i] * (C[i] - 1) / 2; //  nC2
            ans += 1LL * b * (c - C[i]);
        }
    }

    // presentation
    std::cout << ans << std::endl;
    
    return 0;
}

