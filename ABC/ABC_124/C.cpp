#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    int N = S.size();

    std::string p0 = "0"; // parity 0
    std::string p1 = "1"; // parity 1
                          //
    for (int i = 0; i < N - 1; i++) {
        p0 += std::to_string((i + 1) % 2);
        p1 += std::to_string(i % 2);
    }

    int c0 = 0, c1 = 0;
    for (int i = 0; i < N; i++) {
        c0 += (S[i] != p0[i]) ? 1 : 0;
        c1 += (S[i] != p1[i]) ? 1 : 0;
    }

    std::cout << std::min(c0, c1) << std::endl;
    return 0;
}

