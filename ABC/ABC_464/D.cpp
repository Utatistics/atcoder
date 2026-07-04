#include <bits/stdc++.h>

using ll = long long;

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;
        std::string S;
        std::cin >> S;

        std::vector<int> X(N);
        for (int i = 0; i < N; i++) std::cin >> X[i];

        std::vector<int> Y(N - 1);
        for (int i = 0; i < N - 1; i++) std::cin >> Y[i];

        std::string w = "SR";
        std::vector<std::vector<ll>> dp(N+1, std::vector<ll>(2, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 2; j++) {
                int c = (S[i] == w[j]) ? 0 : X[i]; // cost
         
                ll a = dp[i][0] - c; // gets from 'S'
                ll b = dp[i][1] - c; // gets from 'R'
                
                if (i > 0) 
                    b += (w[j] == 'S') ? Y[i - 1] : 0; // 'R' -> 'S' gets gain
                
                dp[i + 1][j] = std::max(a, b);
            }
        }

        std::cout << std::max(dp[N][0], dp[N][1]) << "\n";
    }

    return 0;
}

