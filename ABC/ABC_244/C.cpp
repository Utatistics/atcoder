#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::set<int> s;


    int i = 1;
    int x = -1;
    while (x) {
        for (; i <= 2 * N + 1; i++) {
            if (s.count(i) > 0) continue;
            s.insert(i);
            break;
        }
        std::cout << i << std::endl;
        std::cin >> x;
        s.insert(x);
    }

    return 0;
}

