#include <bits/stdc++.h>

using ll =  long long;

int main() {
    int N;
    ll K;
    std::cin >> N >> K;

    std::vector<int> L(N);
    std::vector<int> C(N);
    
    std::vector<std::vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int l;
        std::cin >> l;
        L[i] = l;
        for (int j = 0; j < l; j++) {
            int a;
            std::cin >> a;
            A[i].push_back(a);
        }
    }
    for (int i = 0; i < N; i++) std::cin >> C[i];
    
    int ki = 0;
    int kj = 0;
    for (int i = 0; i < N; i++) {
        ll cl = 1LL * C[i] * L[i];
        if (K > cl) K -= cl;
        else {
            ki = i;
            kj = (K - 1) % L[i];
            break;
        }
    }

    std::cout << A[ki][kj] << std::endl;
    return 0;
}

