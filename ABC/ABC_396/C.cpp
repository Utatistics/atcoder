#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input
    int N, M;
    std::cin >> N >> M;

    std::vector<int> B(N);
    for (int i = 0; i < N; i++) std::cin >> B[i];
    std::vector<int> W(M);
    for (int i = 0; i < M; i++) std::cin >> W[i];

    // solve
    std::sort(B.begin(), B.end(), [](int a, int b){ return a > b; }); // O(N * logN)
    std::sort(W.begin(), W.end(), [](int a, int b){ return a > b; }); // O(N * logN)
    
    std::vector<ll> S(N);
    for (int i = 0; i < N; i++)
        S[i] = (i == 0) ? B[i] : S[i - 1] + B[i];
    
    std::vector<ll> T(M);
    for (int i = 0; i < M; i++) { // cumurative max
        ll t = (i == 0) ? W[i] : T[i - 1] + W[i];
        T[i] = (i == 0) ? t : std::max(t, T[i - 1]);
    }

    // presentation
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans = std::max(ans, S[i]); // choose only black
        ans = std::max(ans, S[i] + T[std::min(i, M - 1)]);
    }

    std::cout << ans << std::endl;
    return 0;
}
