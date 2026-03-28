#include <bits/stdc++.h>

int main() {
    int N, A, B;
    std::cin >> N >> A >> B;

    std::string S;
    std::cin >> S;

    for (int i = A; i < N - B; i++) {
        std::cout << S[i];
    }
    std::cout << std::endl;

    return 0;
}

