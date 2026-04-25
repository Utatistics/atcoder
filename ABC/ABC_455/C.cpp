#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<int, int>;

int main() {
    int N, K;
    std::cin >> N >> K;

    ll ans = 0;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        ans += A[i];
    }

    std::sort(A.begin(), A.end()); // O(N * logN)
    
    std::deque<P> rle;
    rle.push_back({A[0], 1});
    for (int i = 1; i < N; i++) {
        if (A[i] == rle.back().first) rle.back().second++;
        else rle.push_back({A[i], 1});
    }
    
    std::priority_queue<
        ll,
        std::vector<ll>,
        std::less<ll>  // dafuult comparator, maxHeap, use std::greater for minHeap
    > pq;
    for (P p : rle) pq.push(1LL * p.first * p.second);

    while (K--) {
        ll x = pq.top(); pq.pop();
        ans = std::max(ans - x, 0LL);
    }

    std::cout << ans << std::endl;

    return 0;
}

