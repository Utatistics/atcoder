#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    int argmaxA = 0;
    std::vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        if (i > 0) argmaxA = (A[i] > A[argmaxA]) ? i : argmaxA;
    }
    
    int argmaxB = 0;
    std::vector<ll> B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
        if (i > 0) argmaxB = (B[i] > B[argmaxB]) ? i : argmaxB;
    }

    std::cout << A[argmaxA] + B[argmaxB] << std::endl;
    return 0;
}

