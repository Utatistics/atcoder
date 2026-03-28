#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main () {
    // input
    int N;
    std::cin >> N;

    std::vector<P> A;
    for (int i = 0; i < N; i++) {
        int x, l;
        std::cin >> x >> l;
        A.push_back({x + l, x - l});
    }

    // solve
    std::sort(A.begin(), A.end()); // O(N * logN)
    
    int cnt = 0;
    int rmax = A[0].first;
    for (int i = 1; i < N; i++) {
        auto [r, l] = A[i];
        if (l < rmax) {
            cnt++;
            continue; // removed, no rmax update
        }
        rmax = std::max(rmax, r);
    }

    // presentation
    std::cout << N - cnt << std::endl;
    
    return 0;
}
