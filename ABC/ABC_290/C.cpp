#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<bool> exists(K, false);

    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;

        if (x < K) exists[x] = true;
    }

    int ans = 0;
    while (ans < K && exists[ans]) {
        ++ans;
    }

    std::cout << ans << '\n';
}
