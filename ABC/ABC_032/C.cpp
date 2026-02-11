#include <bits/stdc++.h>

using ll = long long;

int main () {
    int N;
    std::cin >> N;

    ll K;
    std::cin >> K;

    std::vector<ll> S(N);
    for (int i = 0; i < N; i++) std::cin >> S[i];

    // edge cases
    for (int i = 0; i < N; i++) {
        if (S[i] == 0) {
            std::cout << N << std::endl;
            return 0;
        }
    }

    if (K == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    // shakutori
    int ans = 0;

    int r = 0;
    ll s = 1;   // product starts from 1
    for (int l = 0; l < N; l++) {
        while (r < N && s * S[r] <= K) {
            s *= S[r];
            r++;
        }

        ans = std::max(ans, r - l);

        if (r == l) ++r;
        else s /= S[l];
    }

    std::cout << ans << std::endl;
    return 0;
}

