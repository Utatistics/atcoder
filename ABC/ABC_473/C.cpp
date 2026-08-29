#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    std::vector<int> cnt(K, 0);
    
    int M = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        cnt[A[i] - 1]++;

        M = std::max(M, cnt[A[i] - 1]);
    }
    std::sort(cnt.begin(), cnt.end());
    
    int k = 0;
    for (int i = 0; i < K; i++) {
        if (cnt[i] + 1 >= M) {
            k = i;
            break;
        }
    }
    std::cout << K - k << std::endl;
    return 0;
}

