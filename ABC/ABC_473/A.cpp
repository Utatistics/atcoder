#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    
    int ans = 0;
    for (int i = N / 2; i < N ; i++) {
        ans += A[i];
    }

    std::cout << ans << std::endl;
    return 0;
}
