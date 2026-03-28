#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input processing
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N), B(N);

    ll ans = 0;
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < N; i++) std::cin >> B[i];

    // solve 
    for (int i = 0; i < N; i++) ans += std::min(A[i], B[i]);
    for (int i = 0; i < Q; i++) {
        char c;
        int x, v;
        std::cin >> c >> x >> v;
        x--; // 0-index

        int a = A[x], b = B[x];
        if (c == 'A') A[x] = v;
        else B[x] = v;
        ll d = std::min(A[x], B[x]) - std::min(a, b);
        
        // presentation
        ans += d;
        std::cout << ans << std::endl;

    }

    return 0;

}

