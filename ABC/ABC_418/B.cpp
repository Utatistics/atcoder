#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    double ans = 0;
    int N = S.size();
    for (int i = 0; i < N + 1; i++) {
        for (int j = i + 2; j < N + 1; j++) {
            std ::string t = S.substr(i, j - i + 1);
            double s = t.size();
            // std::cout << t << std::endl; // debug

            double x = 0;
            for (char c : t) x += (c == 't') ? 1 : 0;
            
            ans = std::max(ans, (x - 2) / (s - 2));
        }
    }

    std::cout << std::fixed << std::setprecision(17) << ans << std::endl;

    return 0;
}
