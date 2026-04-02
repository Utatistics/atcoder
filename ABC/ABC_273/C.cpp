#include <bits/stdc++.h>

int main() {
    // input
    int N;
    std::cin >> N;

    std::map<int, int> m;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        m[a]++;
    }

    //  solve
    auto it = m.rbegin(); // std::map<int, int>::reverse_iterator
    for (int k = 0; k < N; k++) {
        if (it != m.rend()) {
            std::cout << (*it).second << std::endl;
            it++;
        }
        else {
            std::cout << 0 << std::endl;
        }
    }

    return 0;
}

