#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int> C(N);
    for (int i = 0; i < N; i++) std::cin >> C[i]; 
    for (int i = 0; i < N; i++) 
        if (i % 2 == 1) S[i] ^= 1; // 1 if S[i] == 0, else 1;

    ll ans = 1e18;
    auto solve = [&]() -> void {
        std::vector<ll> L(N + 1); // cost to turn S[0, i) into 0
        std::vector<ll> R(N + 1); // cost to turn S[i, N) is into 1

        for (int i = 0; i < N; i++) {
            L[i + 1] = L[i];
            if (S[i] == '1') L[i + 1] += C[i];
        }
        for (int i = N - 1; i >= 0; i--) {
            R[i] = R[i + 1];
            if (S[i] == '0') R[i] += C[i];
        }
        for (int i = 1; i < N; i++) 
            ans = std::min(ans, L[i] + R[i]);
    };

    solve();
    for (int i = 0; i < N; i++) S[i] ^= 1; // flip over and do it again
    solve();

    std::cout << ans << std::endl;
    return 0;
}

