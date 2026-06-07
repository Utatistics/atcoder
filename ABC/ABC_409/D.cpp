#include <bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;
        std::string s;
        std::cin >> s;

        int l = N; // find l, O(N)
        for (int i = 0; i < N - 1; i++) { // find l
            if (s[i] > s[i + 1]) {
                l = i;
                break;
            }
        }
        if (l == N) {
            std::cout << s << "\n";
            continue;
        }

        int r = l; // find r, O(N)
        for (int i = l + 1; i < N; i++) { 
            if (s[l] < s[i]) {
                r = i;
                break;
            }
            if (i == N - 1) r = N;
        }

        std::string ans = "";
        for (int i = 0; i < l; i++) ans += s[i];
        for (int i = l + 1; i < r; i++) ans += s[i];
        ans += s[l];
        for (int i = r; i < N; i++) ans += s[i];

        std::cout << ans << "\n";
    }

    return 0;
}

