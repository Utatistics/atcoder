#include <bits/stdc++.h>

static constexpr int INF = 1e9;

int main() {

    int N;
    std::cin >> N;

    std::vector<int> L(N);
    for (int i = 0; i < N; i++) std::cin >> L[i];

    std::vector<int> ps(N + 1, 0);
    for (int i = 1; i <= N; i++) ps[i] = ps[i - 1] + L[i - 1];
    
    int ans = INF;
    for (int i = 1; i <= N; i++) {
        int l = ps[i];
        int r = ps[N] - ps[i];
        ans = std::min(ans, std::abs(r - l));
    }

    std::cout << ans << std::endl;

    return 0;
}

