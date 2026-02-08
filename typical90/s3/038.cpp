#include <iostream>

static const long long INF = 1e18;

long long gcd(long long a, long long b) {
    // std::cout << "a=" << a << ", b=" << b << ", a%b=" << a%b << std::endl;
    return b ? gcd(b, a % b) : a;
}

int main() {
    long long A, B;
    std::cin >> A >> B;

    long long ans = (A / gcd(A, B)) * B;
    
    if (ans <= INF) std::cout << ans;
    else std::cout << "Large";

    return 0;
}

