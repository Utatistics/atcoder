#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, L;
    std::cin >> N >> L;

    if (L % 3 != 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<int> cnt(2 * L, 0);
    std::vector<int> pos(N, - 1);

    cnt[0]++; cnt[L]++;
    pos[0] = 0; 
    for (int i = 1; i < N; i++) {
        int d;
        std::cin >> d;
        
        int p = (pos[i - 1] + d) % L;
        cnt[p]++; cnt[p + L]++;
        pos[i] = p;

    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int p = pos[i];
        ans += 1LL * cnt[p + L / 3] * cnt[p + L / 3 * 2];
    }
    ans /= 3;

    std::cout << ans << std::endl;

    return 0;
}

