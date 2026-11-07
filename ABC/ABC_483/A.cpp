#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    if (N % 2 == 0) std::cout << N / 2 << std::endl;
    else std::cout << 1 + N / 2 << std::endl;
    return 0;
}

