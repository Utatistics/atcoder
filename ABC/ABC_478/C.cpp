#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    
    std::vector<int> X = A;
    std::sort(X.begin(), X.end());

    int l = -1;
    int r = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] != X[i]) {
            if (l == -1) l = i;
            r = i;
        }
    }
    if (l == -1) {
        std::cout << "Yes\n";
        return 0;
    }

    if (r - l + 1 <= K) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}
