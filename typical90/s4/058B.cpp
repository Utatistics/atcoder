#include <bits/stdc++.h>

using ll = long long;
static const int M = 1e5; // number of states

int digit_sum(const std::string& s) {
    int sum = 0;
    for (char c : s) sum += c - '0'; // char digit to int
    return sum;
}

int main() {
    int N;
    ll K;
    std::cin >> N >> K;

    int L = 60; // i.e. argmin k (1e18 < 2^k) = 60
    std::vector<std::vector<int>> dp(M, std::vector<int>(L)); // doubling
    for (int x = 0; x < M; x++) {
        int y = digit_sum(std::to_string(x));
        int z = (x + y) % M;
        dp[x][0] = z; // 2^0 (i.e. 1) step from x
    }

    for (int j = 1; j < L; j++) {
        for (int x = 0; x < M; x++) dp[x][j] = dp[dp[x][j-1]][j-1];
    }

    int ans = N;
    for (int j = 0; j < L; j++) {
        if (K & (1LL << j)) ans = dp[ans][j];// e.g. K = 1*2^0 + 0*2^1 +...+ 1*2^L
    }

    std::cout << ans << "\n";
    return 0;
}
