#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    std::vector<int> B(N - 1);
    for (int i = 0; i < N - 1; i++) std::cin >> B[i];


    std::vector<int> A0(N, 0);
    for (int i = 0; i < N - 1; i++) {
        A0[i + 1] = (A0[i] == B[i]) ? 0 : 1;
    }

    std::vector<int> A1(N, 1);
    for (int i = 0; i < N - 1; i++) {
        A1[i + 1] = (A1[i] == B[i]) ? 0 : 1;
    }

    int c0 = 0;
    int c1 = 0;

    for (int i = 0; i < N; i++) {
        if ((A[i] % 2) != A0[i]) ++c0;
        if ((A[i] % 2) != A1[i]) ++c1;
    }

    std::cout << std::min(c0, c1) << std::endl;

    return 0;
}
