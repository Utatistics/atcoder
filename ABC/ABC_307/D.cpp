#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::string ans = "";

    int height = 0; // remaining '(' counts
    for (auto c : S) {
        if (c == ')' && height) {
            while (!ans.empty() && ans.back() != '(') {
                ans.pop_back();
            }
            ans.pop_back(); // pop '('
            --height;
        }
        else if (c == '(') {
            ans += c;
            ++height;
        }
        else {
            ans += c;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

