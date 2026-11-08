#include <bits/stdc++.h>

static const int MAX = 1e5 + 9;

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
   
    int M;
    std::cin >> M;
    std::vector<int> B(MAX + 1);
    for (int i = 0; i < M; i++) {
        int b;
        std::cin >> b;
        ++B[b];
    }
    
    int X;
    std::cin >> X;

    std::vector<bool> dp(X + 1, false);
    dp[0] = true;
    for (int i = 0; i <= X; i++) {
        if (!dp[i]) continue;

        for (int j = 0; j < N; j++) {
            int k = i + A[j]; // next step
            if (k > X || B[k] > 0) continue;
            
            dp[k] = true;
        }
    }

    if (dp[X] > 0) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

