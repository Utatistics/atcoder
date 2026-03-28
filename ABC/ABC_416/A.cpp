#include <bits/stdc++.h>

int main() {
    // input processing
    int N, L, R;
    std::cin >> N >> L >> R;
    std::string S;
    std::cin >> S;

    // solve
    bool ans = true;
    for (int i = L - 1; i < R - 1; i++) {
        if(S[i] != 'o') ans = false;
    }

    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}
