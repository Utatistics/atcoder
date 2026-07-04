#include <bits/stdc++.h>

using P = std::pair<int,int>;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    std::priority_queue<
        P,
        std::vector<P>,
        std::greater<P>> pq; // min heap
   
    int d = 0; // offset
    for (int i = 0; i < N; i++) {
        int c = 0; // removed count
        while (!pq.empty()) {
            P p = pq.top();
            if (p.first + p.second - d <= 0) {
                ++c;
                pq.pop();
            }
            else break;
        }
        int y = A[i] + pq.size() + c;
        pq.push({y, i});
        ++d;
    }

    std::vector<int> ans(N, 0);
    while (!pq.empty()) {
        auto [x, i] = pq.top(); pq.pop();
        ans[i] = x + i - d + 1;
    }

    for (int i = 0; i < N; i++) std::cout << ans[i] << " ";
    std::cout << std::endl;
    
    return 0;
}

