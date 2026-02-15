#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int m = 0;
    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
        m = std::max(m, (int)S[i].size());
    }

    for (int i = 0; i < N; i++) {
        std::string ans = "";
        std::string s = S[i];
        std::string dot((m - (int)s.size()) / 2, '.');
        ans += dot;
        ans += s;
        ans += dot;

        std::cout << ans << std::endl;
    }
    return 0;
}

