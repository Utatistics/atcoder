#include <bits/stdc++.h>

int main () {
    // input processing
    int Q;
    std::cin >> Q;

    // solve
    std::deque<int> dq;
    for (int i = 0; i < Q; i++) {
        int t, x;
        std::cin >> t >> x;
        
        if (t == 1) dq.push_front(x);
        else if (t == 2) dq.push_back(x);
        else if (t == 3) std::cout << dq[--x] << "\n"; // O(1) 
    }

    return 0;
}
