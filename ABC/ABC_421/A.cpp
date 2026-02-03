#include <bits/stdc++.h>

int main() {
    // input processing
    int N;
    std::cin >> N;

    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) std::cin >> S[i];

    // solve
    int X;
    std::cin >> X;
    std::string Y;
    std::cin >> Y;

    // presentation
    if (S[X - 1] == Y) {
        std::cout << "Yes\n";
    }
    else {
        std::cout << "No\n";
    }

    return 0;
}

