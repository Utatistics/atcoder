#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(M);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < M; i++) std::cin >> B[i];
    
    std::sort(A.begin(), A.end()); 
    std::sort(B.begin(), B.end());

    int ans = 0;
    int i = 0; int j = 0;
    while (i < N && j < M) {
        if (2 * A[i] >= B[j]) {
            ++ans;
            ++i; ++j;
        }
        else {
            ++i;
        }
    }

    std::cout << ans << std::endl;
    return 0;
} 
