#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<std::pair<char,int>> rle;
    rle.push_back({S[0], 1});
    for (int i = 1; i < N; i++) {
        if (S[i] == rle.back().first) rle.back().second++;
        else rle.push_back({S[i], 1});
    }
    
    std::vector<int> cnt(26, 0);
    for (auto [s, c] : rle) {
        int i = s - 'a';
        cnt[i] = std::max(cnt[i], c);
    }

    int ans = 0;
    for (int c : cnt) ans += c;
    std::cout << ans << std::endl;

    return 0;
}

