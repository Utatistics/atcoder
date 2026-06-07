#include <bits/stdc++.h>

using ll = long long;

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N, M;
        std::cin >> N >> M;

        ll ans = 0;
        std::vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            std::cin >> A[i];
            ans += A[i];
        }
        for (int i = 0; i < N; i++) {
            std::cin >> B[i];
            ans += B[i];
        }
        
        std::sort(A.begin(), A.end());
        std::sort(B.begin(), B.end());

        int cnt = 0;
        int k = N - 1;
        for (int i = 0; i < N; i++) {
            if (A[i] + B[k] >= M) {
                cnt++;
                k--;
            }
        }

        std::cout << ans - 1LL * M * cnt << "\n";
        
    }
    return 0;
}
