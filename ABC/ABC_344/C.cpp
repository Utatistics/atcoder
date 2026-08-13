#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, M, L, Q;

    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    
    std::cin >> M;
    std::vector<int> B(M);
    for (int i = 0; i < M; i++) std::cin >> B[i];
    
    std::cin >> L;
    std::vector<int> C(L);
    for (int i = 0; i < L; i++) std::cin >> C[i];
    
    std::cin >> Q;
    std::vector<int> X(Q);
    for (int i = 0; i < Q; i++) std::cin >> X[i];
    
    std::set<ll> s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k= 0; k < L; k++) {
                s.insert(A[i] + B[j] + C[k]);
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        if (s.count(X[i]) > 0) std::cout << "Yes\n";
        else std::cout << "No\n";
    }
    return 0;
}

