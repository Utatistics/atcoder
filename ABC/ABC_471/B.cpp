#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int ans = 0;
    std::map<std::string, int> cnt;
    for (int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;

        std::string t = "";
        for (auto c : s) {
            t += std::tolower(c);
        }
        cnt[t]++;
        if (cnt[t] > ans) ans = cnt[t];
    }

    std::cout << ans << std::endl;

    return 0;
}

