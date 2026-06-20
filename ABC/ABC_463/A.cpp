#include <bits/stdc++.h>

int main() {
    int X, Y;
    std::cin >> X >> Y;

    if (X % 16 == 0 && Y % 9 == 0)
        if (X / 16 == Y / 9) std::cout << "Yes\n";
        else std::cout << "No\n";
    else 
        std::cout << "No\n";

    return 0;
}

