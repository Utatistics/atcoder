#include <bits/stdc++.h>

using tup = std::tuple<int, int, char>;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<tup> A;
    for (int i = 0; i < M; i++) {
        int x, y;
        char c;
        std::cin >> x >> y >> c;
        A.emplace_back(x, y, c);

    }
    std::sort(A.rbegin(), A.rend());

    int ymax = -1;
    for (auto [x, y, c] : A) {
        if (c == 'B') {
            ymax = std::max(ymax, y);
        } 
        else {
            if (y <= ymax) {
                std::cout << "No\n";
                return 0;
            }
        }
    }
    std::cout << "Yes\n";
    return 0;
}

