#include <bits/stdc++.h>

std::string parentheses(std::string s) {
    std::string t;
    for (char c : s) {
        t += c;
        int n = t.size();
        if (n >= 4 && t.substr(n - 4) == "(xx)") {
            for (int i = 0; i < 4; i++) t.pop_back();
            t += "xx";
        }    
    }
    return t;
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        std::string A, B;
        std::cin >> A >> B;

        std::string a = parentheses(A);
        std::string b = parentheses(B);

        if (a == b) {
            std::cout << "Yes\n";
        }
        else {
            std::cout << "No\n";
        }
    }

    return 0;
}
