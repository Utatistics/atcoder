#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A;
    for (int i = 1; i <= N; i++) A.push_back(i);

    // solce
    int rc = 0; // rotate count
    while (Q--) {
        int t;
        std::cin >> t;

        if (t == 1) { // update
            int p, x;
            std::cin >> p >> x;
            p--;
            A[(p + rc) % N] = x;
        }
        if (t == 2) { // print
            int p;
            std::cin >> p;
            p--;
            std::cout << A[(p + rc) % N] << std::endl;
        }
        if (t == 3) { // rotate
            ll k;
            std::cin >> k;
            rc = (rc + k) % N;
        }
        
    }
    return 0;
}

