#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    int N = S.size();

    int ans = 0;
    for (int i = 0; i < N; i++) { // odd
        int l = i, r = i;
        int cnt = 0;
        while (l - 1 >= 0 && r + 1 < N && cnt <= 1) {
            --l;
            ++r;
            if (S[l] != S[r]) ++cnt;
            if (cnt <= 1) ++ans;
        }
        ++ans; // length 1
    }
    for (int i = 0; i + 1 < N; i++) { // even
        int l = i, r = i + 1;
        int cnt = (S[l] == S[r]) ? 0 : 1;
        while (l - 1 >= 0 && r + 1 < N && cnt <= 1) {
            --l;
            ++r;
            if (S[l] != S[r]) ++cnt;
            if (cnt <= 1) ++ans;
        }
        ++ans; // length 2
    }

    std::cout << ans << std::endl;
    return 0;
}
