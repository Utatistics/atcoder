#include <bits/stdc++.h>

int main() {
    int M, D;
    std::cin >> M >> D;

    if (M == 1 && D == 7) std::cout << "Yes\n";
    else if (M == 3 && D == 3) std::cout << "Yes\n";
    else if (M == 5 && D == 5) std::cout << "Yes\n";
    else if (M == 7 && D == 7) std::cout << "Yes\n";
    else if (M == 9 && D == 9) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}
