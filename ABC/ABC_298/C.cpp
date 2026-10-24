#include <bits/stdc++.h>

static const int MAX = 2e5 + 1;

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::vector<int>> b2c(N);
    std::vector<std::set<int>> c2b(MAX);

    while (Q--) {
        int type, i, j;
        std::cin >> type;

        if (type == 1) {
            std::cin >> i >> j;

            b2c[j - 1].push_back(i);
            c2b[i].insert(j);
        }
        else if (type == 2) {
            std::cin >> i;
            --i;

            std::sort(b2c[i].begin(), b2c[i].end());
            for (auto x : b2c[i]) std::cout << x << " ";
            std::cout << "\n";
        }
        else {
            std::cin >> i;

            for (auto x : c2b[i]) std::cout << x << " ";
            std::cout << "\n";
        }
    }

    return 0;
}

