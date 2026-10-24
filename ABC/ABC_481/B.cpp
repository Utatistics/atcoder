#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    int ans = A[0] == K;
    
    for (int i = 1; i < N; i++) {
        if (A[i] == K) {
            ++ans;
            continue;
        }
        
        bool flg0 = A[i - 1] < K;
        bool flg1 = A[i] < K;

        if (flg0 != flg1 && A[i - 1] != K) {
            ++ans;
        } 
    }

    std::cout << ans << std::endl;
    return 0;
}

