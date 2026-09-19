#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::string S, T;
    std::cin >> S >> T;

    bool ans = true;
    for (int i = 0; i < N; i++) {
        if (T[i] == '*') continue;
        if (S[i] != T[i]) ans = false;
    }

    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

