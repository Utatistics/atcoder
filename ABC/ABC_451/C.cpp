#include <bits/stdc++.h>

int main() {
    int Q;
    std::cin >> Q;
    
    std::priority_queue<
        int,
        std::vector<int>,
        std::greater<int>> pq;

    while (Q--) {
        int t;
        std::cin >> t;

        if (t == 1) {
            int h;
            std::cin >> h;
            pq.push(h);
        }
        else {
            int h;
            std::cin >> h;
            while (1) {
                if (!pq.empty() && h >= pq.top()) pq.pop();
                else break;
            }    
        }
        std::cout << (int)pq.size() << std::endl;    
    }
    
    return 0;
}

