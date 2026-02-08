#include <iostream>
#include <vector>

int main () {
    int N;
    std::cin >> N;
    std::vector<int> s1(N + 1, 0), s2(N + 1, 0);

    for (int i = 0; i < N; i++) {
        int c, p;
        std::cin >> c >> p;
        s1[i + 1] = s1[i] + (c == 1 ? p : 0);
        s2[i + 1] = s2[i] + (c == 2 ? p : 0);
    }

    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        std::cin >> l >> r;
        int ans1 = s1[r] - s1[l - 1];
        int ans2 = s2[r] - s2[l - 1];
        std::cout << ans1 << " " << ans2 << "\n";

    }

    return 0;
}
