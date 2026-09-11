#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(M);
    for (int i = 0; i < M; i++) {
        std::cin >> A[i];
        --A[i]; // 1 to 0 origin
    }
    
    int i = 0, j = 0;
    std::vector<int> ans(N, -1);
    while (i < N) {
        ans[i] = A[j] - i;
        if (i == A[j]) ++j;
        ++i;
    }

    for (auto a : ans) {
        std::cout << a << "\n";
    }
    return 0;
}

