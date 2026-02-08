#include <bits/stdc++.h>

int main() {
    // input processing
    int Q;
    std::cin >> Q;

    // solve
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int i = 0; i < Q; i++) {
        int t, v;
        std::cin >> t;
        if (t == 1) {
            std::cin >> v;
            pq.push(v);
        }
        // presentation
        if (t == 2) { 
            v = pq.top();
            std::cout << v << "\n";
            pq.pop();
        }
    }

    return 0;
}

