#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    // input
    int N, M;
    std::cin >> N >> M;

    std::vector<P> A;
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        A.push_back({a, b});
    }
    
    // solve
    std::sort(A.begin(), A.end(), [](const P& x, const P& y) {
        return x.second < y.second; // sort by right, ascending
    });

    int ans = 0;
    int k = -1;
    for (const auto& [l, r] : A) {
        if (k < l) {
            k = r - 1;
            ans++;
        }
    }

    // presentation
    std::cout << ans << std::endl;
    return 0;
}
