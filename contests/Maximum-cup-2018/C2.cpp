#include <bits/stdc++.h>

std::vector<int> A;
std::vector<bool> visited;

int dfs(int u) {
    if (visited[u]) return 0;
    visited[u] = true;
    
    int v = A[u];
    return 1 + dfs(v);
}

int main () {
    // input
    int N;
    std::cin >> N;

    A.resize(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i]--; // 0-index
    }

    int ans = 0;
    visited.assign(N, false);

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;

        int cnt = dfs(i);

        if (cnt % 2 == 1) { // a single inconsistency leads to -1
            std::cout << -1 << std::endl;
            return 0;
        }

        ans += cnt / 2;
    }

    // presentation
    std::cout << ans << std::endl;
    return 0;
}
