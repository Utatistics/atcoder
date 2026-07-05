#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<std::vector<P>> A(W);
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        --x;
        A[x].emplace_back(y, i);
    }

    std::vector<int> c(N, 0); // cnt
    int M = N + 1;
    for (auto v : A) {
        M = std::min(M, (int)v.size());
        
        std::sort(v.begin(), v.end());
        int cnt = 0;
        for (auto [y, i] : v) 
            c[i] = cnt++;
    }

    int k = 0;
    std::vector<int> d(M, -1);
    while (k < M) {
        int ymax = 0;
        for (int i = 0; i < W; i++) 
            ymax = std::max(ymax, A[i][k].first);
        if (k == 0) 
            d[k] = ymax;
        else 
            d[k] = std::max(ymax, d[k - 1] + 1);
        d[k] = ymax;
        ++k;
    }

    int Q;
    std::cin >> Q;
    while (Q--) {
        int t, a;
        std::cin >> t >> a;
        --a;

        if (M <= c[a]) std::cout << "Yes\n";
        else if (t < d[c[a]]) std::cout << "Yes\n";
        else std::cout << "No\n";
    }

    return 0;
}

