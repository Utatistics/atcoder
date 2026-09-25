#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);      
    for (int &x : A) {
        std::cin >> x;
    }

    for (int k = 3; k <= N; k++) {
        std::vector<int> B(A.begin(), A.begin() + k);
        std::sort(B.rbegin(), B.rend());

        std::cout << B[2] << '\n';
    }

    return 0;
}
