#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> cnt(101, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        cnt[A[i]]++;
    }
    
    for (int i = 0; i < 101; i++) {
        if (cnt[i] % 2 == 0) cnt[i] = 0;
        else cnt[i] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= 101; i++) {
        ans += i * cnt[i];
    }
    std::cout << ans << std::endl;
    return 0;
}
