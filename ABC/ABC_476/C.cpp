#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    std::priority_queue<
        int,
        std::vector<int>,
        std::less<int>  // maxHeap by dafault, use std::greater<> for minHeap
    > pq;

    for (int i = 0; i < N; i++) {
        pq.push(A[i]);
        if (i < 2) continue;

        int a0 = pq.top(); pq.pop();
        int a1 = pq.top(); pq.pop();
        int a2 = pq.top(); pq.pop();

        std::cout << a2 << "\n";

        pq.push(a0);
        pq.push(a1);
        pq.push(a2);
    }

    return 0;
}

