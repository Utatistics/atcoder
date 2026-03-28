#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    if (S[0] == S[n - 1]) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}
