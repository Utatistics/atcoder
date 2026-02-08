#include <iostream>
#include <vector>
#include <algorithm>

int main () {
    int N;
    std::cin >> N;

    std::vector<int> A, B;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < N; i++) {
        int b;
        std::cin >> b;
        B.push_back(b);
    }

    // solve
    std::sort(A.begin(), A.end(), [](int a0, int a1){return a0 < a1;});
    std::sort(B.begin(), B.end(), [](int b0, int b1){return b0 < b1;});

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += std::abs(A[i] - B[i]);
    }
    std::cout << ans;

    return 0;
}
