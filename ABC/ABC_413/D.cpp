#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        std::vector<int> A(N);
        for (int i = 0; i < N; i++) std::cin >> A[i];

        bool all_same = true; // r = 1
        for (int i = 1; i < N; i++) {
            if (A[i] != A[0]) {
                all_same = false;
                break;
            }
        }
        if (all_same) {
            std::cout << "Yes\n";
            continue;
        }

        int cntx = 0, cnty = 0; // r = -1
        for (int v : A) {
            if (v == A[0]) cntx++;
            if (v == -A[0]) cnty++;
        }
        if (cntx + cnty == N && std::min(cntx, cnty) == N / 2) {
            std::cout << "Yes\n";
            continue;
        }

        std::sort(A.begin(), A.end(), [](int a, int b) { return std::abs(a) > std::abs(b);});
        bool ok = true;
        for (int i = 0; i + 2 < N; i++) {
            if (1LL * A[i + 1] * A[i + 1] != 1LL * A[i] * A[i + 2]) {
                ok = false;
                break;
            }
        }
        std::cout << (ok ? "Yes\n" : "No\n");
    }

    return 0;
}
