#include <bits/stdc++.h>

static const int MAX = 1e9;

using P = std::pair<int, int>;

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<P> A(N);
    for (int i = 0; i < N; i++) {
        int l, r;
        std::cin >> l >> r;
        A[i] = {l, r};

    }
    
    auto f = [&](P p, P q) { return p.second < q.second;};
    std::sort(A.begin(), A.end(), f); // O(N * logN)

    auto solve = [&](int t) {
        int k = 0;
        int rmax = 0;
        for (P p : A) {
            if (k == 0) {
                rmax = p.second;
                k++;
            }
            else {
                if (rmax + t <= p.first) {
                    rmax = p.second;
                    k++;
                }
            }
        }
        return k;
    };

    auto binarySearch = [&]() {
        int left = -1;
        int right = MAX;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (solve(mid) < K) right = mid;
            else left = mid;
        }
        return left;
    };

    int ans = binarySearch();
    if (ans == 0) std::cout << -1 << std::endl;
    else std::cout << ans << std::endl;

    return 0;
}

