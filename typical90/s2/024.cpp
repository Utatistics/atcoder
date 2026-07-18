#include <bits/stdc++.h>

int main () {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N), B(N);
    int sa = 0, sb = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        sa += A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
        sb += B[i];
    }
    int k = 0;
    for (int i = 0; i < N; i++) 
        k += std::abs(A[i] - B[i]);


    bool ans = true;
    if (k > K) ans = false;
    if (sa % 2 == sb % 2 && K % 2 == 1) ans = false;
    if (sa % 2 != sb % 2 && K % 2 == 0) ans = false;

    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";


    return 0;
}
