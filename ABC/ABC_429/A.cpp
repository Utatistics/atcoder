#include <bits/stdc++.h>

int main() {
    // input processing
    int N, M;
    std::cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        std::string ans = (i <= M) ? "OK" : "Too Many Requests";
        std::cout << ans << std::endl;
    }

    return 0;
}

