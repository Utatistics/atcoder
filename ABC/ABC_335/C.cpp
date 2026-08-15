#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<P> A;
    A.emplace_back(1, 0);

    auto push = [&](char c) {
        auto [x, y] = A.back();

        if (c == 'U') ++y;
        if (c == 'D') --y;
        if (c == 'L') --x;
        if (c == 'R') ++x;

        A.emplace_back(x, y);
    };

    int q = 0;

    while (Q--) {
        int t;
        std::cin >> t;

        if (t == 1) {
            char C;
            std::cin >> C;
            push(C);
            ++q;
        } else {
            int p;
            std::cin >> p;

            if (p > q + 1) {
                std::cout << p - q << " 0\n";
            } else {
                auto [x, y] = A[q - p + 1];
                std::cout << x << " " << y << '\n';
            }
        }
    }
}
