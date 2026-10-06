#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<int, int>;

int main() {
    int W, H, N;
    std::cin >> W >> H >> N;

    std::vector<P> C;
    for (int i = 0; i < N; i++) {
        int p, q;
        std::cin >> p >> q;
        C.emplace_back(p, q);
    }

    int A, B;
    std::cin >> A;
    std::vector<int> X(A + 1, 0);
    for (int i = 1; i <= A; i++) std::cin >> X[i];
    std::cin >> B;
    std::vector<int> Y(B + 1, 0);
    for (int i = 1; i <= B; i++) std::cin >> Y[i];

    std::map<P, int> m;
    for (int i = 0; i < N; i++) {
        int x = std::lower_bound(X.begin(), X.end(), C[i].first) - X.begin();
        int y = std::lower_bound(Y.begin(), Y.end(), C[i].second) - Y.begin();
        ++m[std::make_pair(x, y)];
    }

    int ansmin = N + 1; int ansmax = -1;
    for (auto [k, v] : m) {
        ansmin = std::min(ansmin, v);
        ansmax = std::max(ansmax, v);
    }
    if ((ll)m.size() < 1LL * (A + 1) * (B + 1)) ansmin = 0;

    std::cout << ansmin << " " << ansmax << std::endl;
    return 0;
}

// X: [2, 5, ...]
//       x=2       x=5
//         |         |
//         v         v
//    0    |    1    |    2
// <-------|---------|------->

// So:
// p < 2 → region 0
// 2 < p < 5 → region 1
// p > 5 → region 2
// Notice that this corresponds exactly to:
// std::lower_bound(X.begin(), X.end(), p)
