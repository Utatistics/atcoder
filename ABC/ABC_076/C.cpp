#include <bits/stdc++.h>

int t;

bool solve (std::string s, std::string t) {
    for (int i = 0; i < (int)t.size(); i++) {
        if (s[i] != '?' && s[i] != t[i]) return false;
    }
    return true;
}

int main() {
    // input
    std::string S, T;
    std::cin >> S >> T;
    t = (int)T.size();

    // solve
    bool status = false;
    for (auto it = S.rbegin(); it != S.rend(); it++) {
        if (it + t > S.rend()) continue;

        std::string w = ""; // window
        for (int k = t - 1; k >= 0; k--) w += *(it + k);
            
        status = solve(w, T);

        if (status) {
            std::string ans = "";

            auto L = (it + t).base(); // left boundary (forward)
            auto R = it.base();       // right boundary
            for (auto jt = S.begin(); jt != L; jt++) // left 
                ans += (*jt == '?') ? 'a' : *jt;
            ans += T; // middle
            for (auto jt = R; jt != S.end(); jt++) // right 
                ans += (*jt == '?') ? 'a' : *jt;

            // presentation
            std::cout << ans << std::endl;
            return 0;
        }
    }

    if (!status) std::cout << "UNRESTORABLE" << std::endl;

    return 0;
}
