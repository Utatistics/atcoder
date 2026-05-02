#include <bits/stdc++.h>

int main() {
    int X;
    std::cin >> X;

    bool ans = false;
    for (int i = 1; i <= 6; i++) {     
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                if (i + j + k == X) ans = true;
            }
        }
    }

    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}
