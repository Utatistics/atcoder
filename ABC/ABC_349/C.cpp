#include <bits/stdc++.h>

int main() {
    std::string S, T;
    std::cin >> S >> T;
    int N = (int)S.size();

    std::string ans = "No\n";
    int i = 0;
    for (int j = 0; j < N; j++) {
        if (T[i] == std::toupper(S[j])) ++i;
        if (i == 2 && T[i] == 'X') ans = "Yes\n";
        if (i == 3) ans = "Yes\n";
    }

    std::cout << ans;

    return 0;
}

