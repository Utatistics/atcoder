#include <bits/stdc++.h>

using P = std::pair<std::string, std::vector<int>>;

P decompose(const std::string &s) {
    std::string s_;
    std::vector<int> v;
    int cnt = 0;
    for (char c: s) {
        if (c == 'A') {
            ++cnt;
        } else {
            s_ += c;
            v.push_back(cnt);
            cnt = 0; // reset
        }
    }
    v.push_back(cnt);
    return {s_, v};
}

int main() {
    std::string S, T;
    std::cin >> S >> T;
    auto [ss, sv] = decompose(S);
    auto [ts, tv] = decompose(T);
    if (ss != ts) {
        std::cout << -1 << std::endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < (int) sv.size(); i++) {
        ans += abs(sv[i] - tv[i]);
    }
    std::cout << ans << std::endl;
}
