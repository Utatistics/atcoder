#include <bits/stdc++.h>

int main() {
    int N = 4;
    std::vector<int> A = {1, 2, 3, 4};
    std::vector<int> ps(N + 1);
    for (int i = 1; i <= N; i++) ps[i] = ps[i - 1] + A[i - 1];
    
    for (int i = 0; i <= N; i++) {
        std::cout << ps[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

