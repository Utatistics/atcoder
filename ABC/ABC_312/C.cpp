#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N), B(M);
    for (int &a : A) std::cin >> a;
    for (int &b : B) std::cin >> b;

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    auto solve = [&](int k) -> bool {
        int a = std::upper_bound(A.begin(), A.end(), k) - A.begin();
        int b = std::lower_bound(B.begin(), B.end(), k) - B.begin();
        return a >= M - b;
    };

    auto binarySearch = [&]() -> int {
        int l = std::min(A.front(), B.front()) - 1;
        int r = std::max(A.back(), B.back()) + 1;

        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (solve(mid)) r = mid;
            else l = mid;
        }
        return r;
    };

    int ans = binarySearch();

    std::cout << ans << '\n';
}
