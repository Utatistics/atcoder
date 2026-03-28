#include <bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        // input
        int N;
        std::cin >> N;
        std::string S;
        std::cin >> S;

        // solve
        S = '0' + S;
        std::vector<bool> dp(1 << N, false); // include init state '0'
        dp[0] = true; // init

        for (int i = 0; i < (1 << N); i++) { // 0 to 2^N
            if (!dp[i]) continue;

            for (int j = 0; j < N; j++) {
                if ((i & (1 << j)) == 0) { // if jth bit inactive
                    int k = i | (1 << j); // i.e. add chemical
                    if (S[k] == '0') dp[k] = true;
                }
            }
        }

        // presentation
        if (dp[(1 << N) - 1])
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }

    return 0;
}

