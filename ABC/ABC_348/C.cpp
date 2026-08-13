#include <bits/stdc++.h>

static constexpr int MAX = 1e9 + 1;

int main() {
    int N;
    std::cin >> N;

    std::map<int, int> m;
    for (int i = 0; i < N; i++) {
        int a, c;
        std::cin >> a >> c;
        
        m[c] = m[c] == 0 ? a : std::min(m[c], a);
    }

    int ans = 0;
    for (auto [k, v] : m) {
        ans = std::max(ans, v);
    }

    std::cout << ans << std::endl;
    return 0;
}

