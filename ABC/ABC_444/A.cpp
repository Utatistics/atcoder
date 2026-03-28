#include <bits/stdc++.h>

int main() {
    std::string N;
    std::cin >> N;

    bool status = true;
    char n = N[0];
    for (char c : N) {
        if (c != n) {
            status = false;
            break;
        }
    }

    if (status) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

