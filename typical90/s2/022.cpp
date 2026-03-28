#include <iostream>
#include <algorithm>

long long euclidean(long long a, long long b) {
	if (b == 0) return a;
	return euclidean(b, a % b);
}

int main () {
    long long A, B, C;
    std::cin >> A >> B >> C;
    
    long long gcd = euclidean(A, euclidean(B, C));
    // std::cout << gcd << std::endl;   
    std::cout << (A / gcd - 1LL) + (B / gcd - 1LL) + (C / gcd - 1LL) << std::endl;

    return 0;

}
