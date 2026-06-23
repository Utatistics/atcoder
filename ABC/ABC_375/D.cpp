#include <bits/stdc++.h>

using ll = long long;

int main() {
    std::string S;
    std::cin >> S;
    
    int N = S.size();

    std::map<char, int> cntl;
    std::map<char, int> cntr;
    for (char c : S) {
        cntl[c] = 0;
        cntr[c]++;
    }

    ll ans = 0;

    cntr[S[0]]--; // init 
    for (int i = 1; i < N - 1; i++) {
        cntl[S[i - 1]]++;
        cntr[S[i]]--;

        for (auto [k, vl] : cntl) { // O(26)
            int vr = cntr[k];
            ans += 1LL * vl * vr;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}

