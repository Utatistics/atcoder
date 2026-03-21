#include <bits/stdc++.h>

int main() {
    int H, W, Q;
    std::cin >> H >> W >> Q;

    while (Q--) {
        int c;
        std::cin >> c;

        if (c == 1) {
            int R;
            std::cin >> R;
            std::cout << W * R << "\n";
            H -= R;
        }

        if (c == 2) {
            int C;
            std::cin >> C;
            std::cout << H * C << "\n";
            W -= C;
        }
    }

    return 0;
}
