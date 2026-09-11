#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::string S;
    std::cin >> S;

    int ans  = 0;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '0') {
            ans = std::max(ans, std::max(c1 - M, 0) + c2);
            c1 = 0; c2 = 0;
            continue;
        }
        if (S[i] == '1') ++c1;
        if (S[i] == '2') ++c2;    
    }
    if (S[N - 1] != '0') {
        ans = std::max(ans, std::max(c1 - M, 0) + c2);
    }

    std::cout << ans << std::endl;
    return 0;
}

