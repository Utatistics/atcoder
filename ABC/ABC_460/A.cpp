#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    int ans = 0;
    while (M != 0) {
        int x = N % M;
        M = x;
        ans++;
    }

    std::cout << ans << std::endl;
    return 0;
}

