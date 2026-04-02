#include <bits/stdc++.h>

static const int MAX = 51;

int main() {
    // input
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> S(N, std::vector<int>(26, 0));
    for (int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;

        for (char c : s) { 
            int k = c - 'a';
            S[i][k]++;
        }
    }

    std::string ans = "";
    for (int i = 0; i < 26; i++) {
        int cnt = MAX;
        for (int j = 0; j < N; j++) {
            cnt = std::min(cnt, S[j][i]);
        }
        char c = i + 'a';
        for (int i = 0; i < cnt; i++) {
            ans += c;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}

