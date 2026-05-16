#include <bits/stdc++.h>

using ll = long long;

int main() {
    std::string S;
    std::cin >> S;

    int N = S.size();

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] != 'C') continue;
        int l = 1 + std::min(i - 0, N - i - 1); // max length
        ans += l;
    }

    std::cout << ans << std::endl;
    return 0;
}
