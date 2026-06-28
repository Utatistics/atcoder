#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<P>> A(M);
    std::vector<int> cnt(N, 0);

    for (int i = 0; i < N; i++) {
        int a, d, b;
        std::cin >> a >> d >> b;
        --a; --d; --b;

        cnt[a]++;
        A[d].push_back({a, b});
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (cnt[i] > 0) ans++;
    }

    for (int i = 0; i < M; i++) {
        for (auto [a, b] : A[i]) {
            cnt[a]--;
            if (cnt[a] == 0) ans--;

            cnt[b]++;
            if (cnt[b] == 1) ans++;
        }

        std::cout << ans << "\n";
    }

    return 0;
}
