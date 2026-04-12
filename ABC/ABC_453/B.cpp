#include <bits/stdc++.h>

int main() {
    int T, X;
    std::cin >> T >> X;

    int prev = 0;
    for (int i = 0; i <= T; i++) {
        int a;
        std::cin >> a;

        if (i == 0) {
            std::cout << i << " " << a << "\n";
            prev = a;
        }
        else {
            if (std::abs(a - prev) >= X) {
                std::cout << i << " " << a << "\n"; 
                prev = a;
            }
        }
    }

    return 0;
}

