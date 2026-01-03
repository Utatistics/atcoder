#include <iostream>
#include <stack>

int main () {
    int Q;
    std::cin >> Q;
    std::stack<int> s; s.push(0);
    const int INF = 1000000000;
    
    for (int q = 0; q < Q; q++) {
        int t; // query type
        std::cin >> t;
        if (t == 1) {
            char b;
            std::cin >> b;
            int x = s.top() + (b =='(' ? 1: -1);
            if (x < 0) s.push(-INF);
            else s.push(x);
        } else {
            s.pop();
        }
        // bracket string assessment
        if (s.top() == 0) std::cout << "Yes\n";
        else std::cout << "No\n";
    }
    return 0;
}
