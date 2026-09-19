#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    std::string ans = "";
    for (auto c : S) {
        ans += c;
        ans += "o";
    }

    for (int i = 0; i < (int)ans.size() - 1; i++) {
        std::cout << ans[i];
    }
    std::cout << std::endl;
    return 0;
}

