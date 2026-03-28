#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    if ((int)S.size() % 5 == 0)
        std::cout << "Yes\n";
    else 
        std::cout << "No\n";

    return 0;
}

