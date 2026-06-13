#include <bits/stdc++.h>

using P = std::pair<int,int>;

int main() {
    int N;
    std::cin >> N;

    std::vector<P> A;
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        A.push_back({x, y});
    }

    std::sort(A.begin(), A.end());

    int ans = 0;
    int ymin = N + 1;
    for (int i = 0; i < N; i++) {
        int y = A[i].second;
        if (ymin > y) ans++;
        ymin = std::min(ymin, y);
    }

    std::cout << ans << std::endl;
    return 0;
}
