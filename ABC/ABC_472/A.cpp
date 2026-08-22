#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    int N = (int)S.size();
    for (int i = 0; i < N; i++) {
        if (S[i] != 'A') S[i] = '.';
    }

    std::cout << S << std::endl;
    return 0;
}

