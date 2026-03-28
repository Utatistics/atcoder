#include <bits/stdc++.h>

// 6 17 2 4 17 19 1 7
//   *            *
// 7 6 17 2 4 17 19 1
//   *            *

int mod(int a, int b) {return (a % b + b) % b;}

int main () {
    // input processing
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    // solve
    int cnt = 0;
    for (int i = 0; i < Q; i++) {
        int t;
        std::cin >> t; // query type

        if (t == 1) { // swap
            int x, y;
            std::cin >> x >> y;
            x--; y--;
            std::swap(A[mod(x - cnt, N)], A[mod(y - cnt, N)]);
        }
        else if (t == 2) { // rotat
            int x, y;
            std::cin >> x >> y;
            cnt = (cnt + 1) % N;
        }
        else if (t == 3) {
            int x, y;
            std::cin >> x >> y;
            x--;
            std::cout << A[mod(x - cnt, N)] << "\n";
        }

    }

    return 0;

}
