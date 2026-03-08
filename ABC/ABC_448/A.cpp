#include <bits/stdc++.h>

int main() {
    int N, X;
    std::cin >> N >> X;

    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        if (a < X) {
            std::cout << 1 << std::endl;
            X = a;
        }
        else {
            std::cout << 0 << std::endl;
        }
    }
    
    return 0;
}

