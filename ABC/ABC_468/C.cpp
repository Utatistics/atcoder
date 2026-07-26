#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) std::cin >> P[i];
    for (int i = 0; i < N; i++) std::cin >> Q[i];

    ll ans = 0;

    std::vector<int> A;
    std::vector<bool> cnt(N + 1, false);

    auto dfs = [&](auto f) -> void {
        if ((int)A.size() == N) {
            if (P < A && A < Q) ++ans;
            return;
        }

        for (int r = 1; r <= N; r++) {
            if (cnt[r]) continue;
            cnt[r] = true;
            A.push_back(r);
            f(f);
            A.pop_back(); // revert
            cnt[r] = false;
        }
    };

    dfs(dfs);

    std::cout << ans << std::endl;
    return 0;
}

