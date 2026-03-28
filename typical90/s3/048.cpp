#include <bits/stdc++.h>

using ll = long long;

int main () {
    // input processing
    int N, K;
    std::cin >> N >> K;

    std::vector<int> C(2 * N);
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        C[i] = b;
        C[i + N] = a - b;
    }

    // solve
    // O(N * logN)
    std::sort(C.begin(), C.end(), [](int a, int b){ return a > b; });
    
    ll ans = 0;
    for (int k = 0; k < K; k++) ans += C[k];

    std::cout << ans << std::endl;

    return 0;
}
