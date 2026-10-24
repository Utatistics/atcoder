#include <bits/stdc++.h>

int main() {
    int N, K, T;
    std::cin >> N >> K >> T;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    std::sort(A.begin(), A.end());

    int ans = 0;

    auto ceil = [&](int x, int k) -> int {
        return (x + k - 1) / k; // e.g. x + 1 / 2
    };
    
    int R = 0;
    for (int i = 0; i < N && A[i] < T; i++) {
        if (A[i] > R) {
            ans += ceil(A[i] - R, K);
        }
        R = std::max(R, A[i] + K);
    }
    if (R < T) ans += ceil(T - R, K);

    std::cout << ans << '\n';
}
