#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::set<int>> vs(M);
    for (int i = 0; i < M; i++) {
        int C;
        std::cin >> C;

        for (int j = 0; j < C; j++) {
            int a;
            std::cin >> a;
            vs[i].insert(a);
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << M); i++) {
        std::set<int> s;
        for (int j = 0; j < M; j++) { // checking jth bit of given i
            if (i & (1 << j)) {
                s.insert(vs[j].begin(), vs[j].end());
            }
        }
        if ((int)s.size() == N) ++ans;
    }

    std::cout << ans << std::endl;
    
    return 0;
}

