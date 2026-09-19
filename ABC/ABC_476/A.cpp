#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    int N = (int)S.size();

    std::string T = S;
    if (S[N - 1] == 'e') {
        T += "r";
    }
    else {
        T += "er";

    }
    std::cout << T << std::endl;
    return 0;
}

