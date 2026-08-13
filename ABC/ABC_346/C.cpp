#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, K;
    std::cin >> N >> K;

    ll ans = 1LL * K * (K + 1) / 2;
    std::map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        if (a > K) continue;
        if (cnt.count(a) == 0) ans -= a;
        cnt[a]++;
    }

    std::cout << ans << std::endl;
    return 0;
}

