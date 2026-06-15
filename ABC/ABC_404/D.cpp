#include <bits/stdc++.h>

using ll = long long;
static const ll MAX = 2 * 1e10;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> C(N);
    for (int i = 0; i < N; i++) std::cin >> C[i];

    std::vector<std::vector<int>> m(N); // zoo : [animal]
    for (int i = 0; i < M; i++) {
        int K;
        std::cin >> K;
        for (int j = 0; j < K; j++) {
            int a;
            std::cin >> a;
            --a; // 0 index
            m[a].push_back(i);
        }
    }
 
    ll ans = MAX;
    std::vector<int> cntz;
    auto dfs = [&](auto f) -> void {
        if ((int)cntz.size() == N) { // validate selection
            std::vector<int> cnta(M);
            for (int i = 0; i < N; i++) {
                for (int a : m[i]) 
                    cnta[a] += cntz[i];
            }
    
            bool status = true;
            for (int c : cnta) if (c < 2) status = false;
            if (status) {
                ll cost = 0;
                for (int i = 0; i < N; i++) cost += 1LL * C[i] * cntz[i];
                ans = std::min(ans, cost);

            }
            return;
        }

        for (int r = 0; r < 3; r++) {
            cntz.push_back(r);
            f(f);
            cntz.pop_back(); // revert
        }
    };

    dfs(dfs);

    std::cout << ans << std::endl;

    return 0;
}

