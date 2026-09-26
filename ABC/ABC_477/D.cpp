#include <bits/stdc++.h>

using P = std::pair<int, char>;

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> X(N, 0); // the most rececnt vulnarability
    std::vector<char> C(N, '.');
    std::vector<P> paint; // type 2

    int q = 0;
    while (Q--) {
        int t;
        std::cin >> t;

        if (t == 1) {
            int x;
            std::cin >> x;
            --x;

            if (C[x] == '.') {
                X[x] = q; // was blocked
                C[x] = '#';
            }
            else {
                C[x] = '.';
            }
        }

        else {
            int c;
            std::cin >> c;
            paint.emplace_back(q, c);
        }
        ++q;
    }


    return 0;
}

