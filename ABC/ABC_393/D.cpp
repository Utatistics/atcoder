#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    ll c = 0; // init
    int rc = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            c += i - rc;
            ++rc;
        }
    }

    ll ans = c;
    int lc = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '0') {
            c += lc;
            c -= rc;
            ans = std::min(ans, c);
        }
        else {
            ++lc;
            --rc;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
