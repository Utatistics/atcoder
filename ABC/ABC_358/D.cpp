#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < M; i++) std::cin >> B[i];
    
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    std::vector<int> C(M, -1);
    int j = 0;
    for (int i = 0; i < M; i++) {
        if (B[i] <= A[j]) {
            C[i] = A[j];
            ++j; // consume
            continue;
        }
        while (B[i] > A[j] && j + 1 < N) {
            ++j;
            if (B[i] <= A[j]) {
                C[i] = A[j];
                ++j;
                break;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < M; i++) {
        if (C[i] < 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
        ans += C[i];
    }

    std::cout << ans << std::endl;
    return 0;
}
