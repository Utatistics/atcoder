#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    std::priority_queue<
        P,
        std::vector<P>,
        std::greater<P>
    > pq; // min heap 

    std::vector<int> ans(N, 0);
    for (int i = 0; i < N; i++) {
        while (!pq.empty()) {
            P p = pq.top();
            if (p.first <= i) {
                pq.pop();
            } else {
                break;
            }
        }
        int y = A[i] + (int)pq.size(); 
        int expire = i + y + 1;
        pq.push({expire, i});
    }

    int d = N;
    while (!pq.empty()) { 
        auto [x, i] = pq.top();
        pq.pop();
        ans[i] = x - d;
    }
    for (int i = 0; i < N; i++) std::cout << ans[i] << " ";
    std::cout << std::endl;

    return 0;
}
