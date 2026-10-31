#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    int cnt = 0;
    for (auto c : S) if (c == 'o') ++cnt;
    
    if (cnt % 2 == 0) std::cout << "even\n";
    else std::cout << "odd\n";
    return 0;
}

