#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0) std::cout << "Fizz\n";
        else std::cout << i << "\n";
    }
    return 0;
}

