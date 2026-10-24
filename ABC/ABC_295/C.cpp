#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::unordered_map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;

        cnt[a]++;
    }

    int ans = 0;
    for (auto [a, c] : cnt) ans += (c / 2);
    
    std::cout << ans << std::endl;
    
    return 0;
}

