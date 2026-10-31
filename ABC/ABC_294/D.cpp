#include <bits/stdc++.h>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    int minx = 0;
    std::set<int> s;
    while (Q--) {
        int type;
        std::cin >> type;

        if (type == 1) {
            s.insert(++minx);
        }
        else if (type == 2) {
            int x;
            std::cin >> x;

            s.erase(x);
        }
        else {
            std::cout << *s.begin() << "\n";
        }
    }
    return 0;
}

