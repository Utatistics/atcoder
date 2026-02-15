int main () {
    
    int N; // possible states
    int M; // e,g. 1e18
    int K; // i.e. argmin k (M < 2^k) = 60
    std::vector<std::vector<int>> dp(N, std::vector<int>(K)); // doubling
    for (int x = 0; x < N; x++) {
        // logic here
        // get i.e. get next step from x
        dp[x][0]; // 2^0 (i.e. 1) step from x
    }

    for (int j = 1; j < K; j++) { // get recursion
        for (int x = 0; x < N; x++) dp[x][j] = dp[dp[x][j-1]][j-1];
    }

    int ans; // init
    for (int j = 0; j < M; j++) {
        if (M & (1LL << j)) ans = dp[ans][j]; // e.g. K = 1*2^0 + 0*2^1 +...+ 1*2^L
    }
}
