#include <bits/stdc++.h>

int main() {
    // input
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    std::unordered_map<int, int> dp;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int p = dp[A[i] - 1] + 1;
        dp[A[i]] = p;
        ans = std::max(ans, p);
    }

    std::cout << ans << std::endl;

    return 0;
}
