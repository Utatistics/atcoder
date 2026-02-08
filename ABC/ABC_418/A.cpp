#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    if (N >= 3 && S.substr(N - 3, N) == "tea") std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

