#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<int, int>;

int main() {
    int N, K;
    std::cin >> N >> K;

    ll cnt = 0;
    std::vector<P> v(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        v[i] = {a, b};

        cnt += b;
    }
    if (cnt <= K) { // edge case
        std::cout << 1 << std::endl;
        return 0;
    }

    std::sort(v.begin(), v.end());
    
    int ans = v.back().first + 1;
    for (int i = 0; i < N; i++) {
        auto [a, b] = v[i];
        if (cnt - b <= K) {
            ans = a + 1;
            break;
        }
        cnt -= b;
    }

    std::cout << ans << std::endl;
    return 0;
}

