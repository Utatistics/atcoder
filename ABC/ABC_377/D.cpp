#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> minR(M + 1, M + 1);
    for (int i = 0; i < N; i++) {
        int l, r;
        std::cin >> l >> r;
        minR[l] = std::min(minR[l], r);
    }

    int m = M + 1;
    for (int i = M; i >= 1; i--) {
        m = std::min(m, minR[i]);
        minR[i] = m;
    }

    ll ans = 0;
    int r = 1;
    for (int l = 1; l <= M; l++) {
        while(r < minR[l]) {
            ++r;
        }
        ans += r - l;
    }

    std::cout << ans << '\n';
    return 0;
}
