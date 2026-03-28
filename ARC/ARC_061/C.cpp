#include <bits/stdc++.h>

using ll = long long;

ll solve(std::string s) {
    ll res = 0;
    std::string t = ""; // buffer str
    for (char c : s) {
        if (c != '+') {
            t += c;
        }
        else {
            res += std::stol(t);
            t = ""; // flish
        }
    }
    res += std::stol(t); // remining digits
    return res;
}

int main() {
    // input
    std::string S;
    std::cin >> S;

    // solve
    ll ans = 0;

    int N = S.size();
    std::string s = "";
    s += S[0]; // init
    for (int i = 0; i < (1 << (N - 1)); i++) { // 0 to 2^N - 1
        // std::cout << std::bitset<4>(i) << std::endl; // debug
        for (int j = 0; j < N - 1; j++) {
            if ((i & (1 << j))) s += '+';
            s += S[j + 1];
        }
        // std::cout << s << std::endl; // debug
        ans += solve(s);
        s = S[0]; // flish
    }
    
    // presentaito
    std::cout << ans << std::endl;
    
    return 0;
}

