#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::map<int, std::vector<P>> m;

    std::vector<int> S(N, 0);
    while(Q--) {
        int L, R, X;
        std::cin >> L >> R >> X;

        if (m[X].count > 0) {
            auto [l, r] = m[X];
            m[X] = 
        }

    }
    return 0;
}

