#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> X(N);
    for (int i = 0; i < N; i++) std::cin >> X[i];
    std::vector<int> P(N);
    for (int i = 0; i < N; i++) std::cin >> P[i];
    std::vector<ll> ps(N + 1, 0);
    for (int i = 1; i <= N; i++) ps[i] = ps[i - 1] + P[i - 1];


    int Q;
    std::cin >> Q;

    while (Q--) {
        int L, R;
        std::cin >> L >> R;
        
        int i = std::lower_bound(X.begin(), X.end(), L) - X.begin(); // i >= L 
        int j = std::upper_bound(X.begin(), X.end(), R) - X.begin(); // j > R
        
        ll ans = ps[j] - ps[i];
        std::cout << ans << "\n";
    }
    
    return 0;
}

