#include <bits/stdc++.h>

int main() {
    std::string S, T;
    std::cin >> S >> T;

    int N = S.size(), M = T.size();

    auto f = [](char a, char b) {
        return a == b || a == '?' || b == '?';
    };

    std::vector<bool> pf(M + 1, true); // S' == T for the first x chars? 
    std::vector<bool> sf(M + 1, true); // S' == T for the last M - x chars?

    for (int i = 0; i < M; i++) 
        pf[i + 1] = pf[i] && f(S[i], T[i]);
    for (int i = M - 1; i >= 0; i--) 
        sf[i] = sf[i + 1] && f(S[N - M + i], T[i]); // i + (N - M)

    for (int x = 0; x <= M; x++) {
        std::cout << (pf[x] && sf[x] ? "Yes\n" : "No\n");
    }

    return 0;
}
