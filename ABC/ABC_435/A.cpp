#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; i++) ans += i;

    std::cout << ans << std::endl;
    
    return 0;
}

