#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<int, int>;

int main() {
    int N;
    std::cin >> N;

    ll s = 0; // sholdder sum
    std::vector<P> A(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        A[i] = {a, b};
        s += a;
    }

    ll ans = -1;
    for (auto p : A) {
        ans = std::max(ans, s - p.first + p.second);
    }
    std::cout << ans << std::endl;

    return 0;
}

