#include <bits/stdc++.h>

using tup = std::tuple<int, int, int>;

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<tup> events;
    for (int i = 0; i < N; i++) { // s - x <= -D < t - x
        int s, t, x;
        std::cin >> s >> t >> x;

        events.emplace_back(s - x, x, 1);
        events.emplace_back(t - x, x, -1);
    }
    std::sort(events.begin(), events.end());

    std::vector<int> D(Q);
    for (int i = 0; i < Q; i++) std::cin >> D[i];

    std::set<int> se;
    std::vector<int> ans(Q);

    int M = (int)events.size();
    int id = 0; // event id

    for (int i = 0; i < Q; i++) {
        int dt = D[i]; // departure time

        while (id < M && std::get<0>(events[id]) <= dt) { // event time <= dt
            auto [_, x, flg] = events[id++];

            if (flg == 1) se.insert(x); // event outbreak
            else se.erase(x); // event terminated
        }

        if (se.empty()) ans[i] = -1;
        else ans[i] = *se.begin();
    }

    for (int i = 0; i < Q; i++) {
        std::cout << ans[i] << '\n';
    }

    return 0;
}
