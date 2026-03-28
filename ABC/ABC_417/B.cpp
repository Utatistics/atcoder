#include <bits/stdc++.h>

int main() {
    // input processing
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(M);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < M; i++) std::cin >> B[i];

    // solve
    for (int i = 0; i < M; i++) {
        int k = 0;
        while (k < N) {
            if (B[i] == A[k]) {
                A[k] = -1;
                break;
            }
            else k++;
        }
    }

    // presentation
    for (int i = 0; i < N; i++) 
        if (A[i] > 0) std::cout << A[i] << " ";
    std::cout << std::endl;
    return 0;
}

