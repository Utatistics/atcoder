#include <bits/stdc++.h>

int main() {
    // input processing
    int Q;
    std::cin >> Q;

    // solve
    int v = 0;
    bool p = false;
    for (int i = 0; i < Q; i++) {
        int a;
        std::cin >> a;
        if (a == 1)
            v++;
        else if (a == 2) {
            v = (v > 0) ? v - 1 : v;
        }
        else if (a == 3) {
            p = (p) ? false : true;
        }

        // presentation
        if (v >= 3 && p == true) std::cout << "Yes\n";
        else std::cout << "No\n";
    }

    return 0;
}

