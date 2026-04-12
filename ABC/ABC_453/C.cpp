#include <bits/stdc++.h>

int main() {
    // input
    int N;
    std::cin >> N;

    std::vector<double> L(N);
    for (int i = 0; i < N; i++) std::cin >> L[i];

    // solve
    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {  
        double x = 0.5;
        bool sign = true; // true if positive else false
        
        int cnt = 0;
        for (int j = 0; j < N; j++) { 
            bool sign_ = sign;
            if (i & (1 << j)) x += L[j];
            else x -= L[j];

            sign = (x > 0);
            if (sign != sign_) cnt++;
            sign_ = sign;
        }
        ans = std::max(ans, cnt);
    }
    
    // presentation
    std::cout << ans << std::endl;

    return 0;
}
