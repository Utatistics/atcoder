#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int m = 0;
    std::vector<int> cnt(N, 0);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        ++cnt[a];

        m = std::max(m, cnt[a]);
    }

    std::cout << N - m << std::endl;
    return 0;
}

