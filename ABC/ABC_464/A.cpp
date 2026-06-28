#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    int ce = 0;
    int cw = 0;
    for (char c : S) {
        if (c == 'E') ce++;
        else cw++;
    }

    if (ce > cw) std::cout << "East\n";
    else std::cout << "West\n";

    return 0;
}

