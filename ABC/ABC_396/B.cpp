#include <bits/stdc++.h>

int main() {
    int Q;
    std::cin >> Q;

    std::stack<int> S;
    for (int i = 0; i < 100; i++) S.push(0);

    while (Q--) {
        int c;
        std::cin >> c;

        if (c == 1) {
            int x;
            std::cin >> x;
            S.push(x);
        }
        else if  (c == 2) {
            int y = S.top();
            std::cout << y << std::endl;
            S.pop();
        }
        
    }
    return 0;
}

