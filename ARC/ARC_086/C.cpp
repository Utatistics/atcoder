#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, P>> A(N + 1);
    A[0] = {0, {0, 0}};

    for (int i = 1; i <= N; i++) {
        int t, x, y;
        std::cin >> t >> x >> y;
        A[i] = {t, {x, y}};
    }

    bool ans = true;
    for (int i = 0; i < N; i++) {
        int t = A[i].first;
        auto [x, y] = A[i].second;
        int nt = A[i + 1].first;
        auto [nx, ny] = A[i + 1].second;

        if (std::abs(nx - x) + std::abs(ny - y) > nt - t) {
            ans = false;
            break;
        }
        if (std::abs(nx - x + ny - y) % 2 != (nt - t) % 2) {
            ans = false;
            break;
        } 
    }

    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

