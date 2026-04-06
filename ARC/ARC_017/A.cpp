#include <bits/stdc++.h>

bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }

    return true;
}

int main() {
    int N;
    std::cin >> N;

    if (isPrime(N)) std::cout << "YES\n";
    else std::cout << "NO\n";

    return 0;
}

