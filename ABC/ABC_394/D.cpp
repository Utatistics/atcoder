#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    int N = S.size();
    std::stack<char> s;

    auto f = [&](char c, char t) -> bool { // check if match
        if (c == ')' && t == '(') return true;
        if (c == ']' && t == '[') return true;
        if (c == '>' && t == '<') return true;
        return false;
    };

    auto solve = [&](auto&& g, int i) -> bool {
        if (i == N) 
            return s.empty();

        char c = S[i];
        if (c == '(' || c == '[' || c == '<') {
            s.push(c);
        }
        else {
            char t = s.top();
            if (s.empty()) return false; // won't even have a chance
            if (f(c, t)) s.pop(); // only chance to close
            else return false; // will not be closed ever
        }

        return g(g, i + 1);
    };

    if (S[0] == ')' || S[0] == ']' || S[0] == '>') { // edge case
        std::cout << "No\n";
        return 0;
    }

    s.push(S[0]);
    bool ans = solve(solve, 1);
    std::cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}

