#include <bits/stdc++.h>

using ll = long long;

int main() {
    ll r1, c1, r2, c2;
    std::cin >> r1 >> c1 >> r2 >> c2;
    ll p = std::abs(r2 - r1), q = std::abs(c2 - c1);
    
    auto solve = [&]() -> ll {
        if (p == 0 && q == 0) return 0; // no move
        
        if (p == q) return 1; // diag 
        if (p + q <= 3) return 1; // cross
        
        if ((p + q) % 2 == 0) return 2; // diag + diag
        if (p + q <= 6) return 2; // cross + cross
        if (std::abs(p - q) <= 3) return 2; // diag + cross (cross + diag)
        
        return 3; 
    };

    std::cout << solve() << std::endl;
}
