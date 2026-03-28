#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    // solve
    std::vector<int> B(2 * N);
    for (int i = 0; i < N; i++) {
        B[i] = A[i];
        B[i + N] = A[i];
    }
    std::vector<ll> ps(2 * N);
    for (int i = 0; i < 2 * N; i++)
        ps[i] = (i == 0) ? B[i] : ps[i - 1] + B[i];
    
    int cnt = 0; // rotate count
    while (Q--) {
        int t;
        std::cin >> t;

        if (t == 1) {
            int c;
            std::cin >> c;
            cnt += c;
        } else {
            ll ans;
            int l, r;
            std::cin >> l >> r;
            l--; r--; // 0 index
            l += cnt % N; r += cnt % N; // rotate!
            if (l == 0) ans = ps[r];
            else ans = ps[r] - ps[l - 1];
            std::cout << ans << std::endl;

        }
        
    }
    return 0;
}

