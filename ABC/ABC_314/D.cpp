#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int Q;
    std::cin >> Q;

    int q = 0;
    int k = 0; // last flip 
    int T = -1;
    std::vector<int> X(Q, -1);
    while (Q--) {
        int t, x;
        char c;
        std::cin >> t >> x >> c;
        --x;

        if (t == 1) {
            S[x] = c;
            X[q] = x;
        }
        else {
            k = q;
            T = t;
        }
        ++q;
    }
    std::vector<bool> r(N, false);
    for (int i = k + 1; i < q; i++) {
        if (X[i] < 0) continue;
        r[X[i]] = true;
    }

    for (int i = 0; i < N; i++) {
        if (r[i] || T < 0) continue;
        S[i] = T == 2 ? std::tolower(S[i]) : std::toupper(S[i]);
    }
    std::cout << S << std::endl;
    return 0;
}

