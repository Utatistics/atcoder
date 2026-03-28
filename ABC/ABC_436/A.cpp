#include <bits/stdc++.h>

int main() {
    // input processing
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    // solve
    int diff = N - (int)S.size();

    std::string padding = "";
    for (int i = 0; i < diff; i++) {
         padding += 'o';
    }

    // presentation
    std::cout << padding + S << std::endl;

    return 0;
}

