#include <bits/stdc++.h>

int eval(const std::string& s) {
    int res = s[0] - '0';

    for (int i = 1; i < (int)s.size(); i += 2) {
        char op = s[i];
        int num = s[i + 1] - '0';
        res += (op == '+') ? num : -1 * num;
    }

    return res;
}

auto c2s(char c) { return std::to_string(c - '0'); }

int main() {
    std::string S;
    std::cin >> S;

    std::string ans = "";

    int N = S.size();
    std::string s = c2s(S[0]);
    for (int i = 0; i < (1 << (N - 1)); i++) { // subset 0 to 2^N - 1 
        for (int j = 0; j < (N - 1); j++) { // checking jth bit of given i
            s += (i & (1 << j)) ? '+' : '-'; // operator
            s += c2s(S[j + 1]); // digit    
        }
        // std::cout << s << "=>" << eval(s) << std::endl;
        if (eval(s) == 7) ans = s + "=7";
        
        if (*ans.end() == '7') break;
        else s = c2s(S[0]); // flush
    }

    std::cout << ans << std::endl;
    
    return 0;
}

