#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int b = 1;
    for (int i = 0; i < N; i++) {
        b *= 2;
    }
    std::cout << b - (2*N) << std::endl;
    
    return 0;
}

