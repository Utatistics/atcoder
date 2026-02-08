#include <iostream>
#include <vector>

int main () {
    // input processing
    int N, K;
    std::cin >> N >> K;
    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < N; i++) std::cin >> B[i];
    
    // solve
    int d = 0;
    for (int i = 0; i < N; i++) {
        d += std::abs(A[i] - B[i]);
    }

    // // debug
    // std::cout << K << std::endl;
    // std::cout << d << std::endl;
    
    if (K < d) {
        std::cout << "No";
        return 0;
    }
    if ((K - d) % 2 != 0) {
        std::cout << "No";
        return 0;
    }
    std::cout << "Yes" << std::endl;
    return 0;

}
