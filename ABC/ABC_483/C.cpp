#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> cnt(N, 0);
    std::vector<std::vector<int>> B(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        --a; --b;

        ++cnt[a];
        B[a].push_back(b);
    }
    std::vector<P> A;
    for (int i = 0; i < N; i++) A.emplace_back(cnt[i], i);

    auto comparator = [](const P& a, const P& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    };
    std::sort(A.begin(), A.end(), comparator);

    for (int a = 0; a < N; a++) {
        auto [cntmax, ans] = (A[0].second != a) ? A[0] : A[1];

        for (auto b : B[a]) { // update cnt
            ++cnt[b];

            if (cnt[b] == cntmax && b < ans) {
                ans = b;
            }
            else if (cnt[b] > cntmax) {
                cntmax = cnt[b];
                ans = b;
            }
        }
        std::cout << ans + 1 << '\n';

        for (auto b : B[a]) { // restore cnt
            --cnt[b];
        }
    }

    return 0;
}
