#include <bits/stdc++.h>

int main() {
    int X, Y, Z;
    std::cin >> X >> Y >> Z;

    bool ans = false;
    for (int x = X, y = Y; y < X * Z; x++, y++) {
        if (y * Z == x) ans = true;
    }
    
    if (ans)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
    
    Y < X * Z;

    return 0;
}

