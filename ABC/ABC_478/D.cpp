#include <bits/stdc++.h>

using tup = std::tuple<int, int, int>;

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<tup> events;
    std::vector<int> cnt(Q); // 1 <= X <= Q

    while (Q--) {
        int L, R, X;
        std::cin >> L >> R >> X;
        --L; // [L, R) *half open
        --X; // 0 index

        events.emplace_back(L, X, 1);
        events.emplace_back(R, X, -1);
    }
    std::sort(events.begin(), events.end()); // event sort

    int ans = 0;
    
    int j = 0; // event index
    int M = (int)events.size();
    
    for (int i = 0; i < N; i++) {
        while (j < M && std::get<0>(events[j]) == i) {
            auto [_, x, s] = events[j++];

            if (cnt[x]) --ans;
            cnt[x] += s;
            if (cnt[x]) ++ans;
        }
        std::cout << ans << " ";
    }
    std::cout << '\n';
    
    return 0;
}
