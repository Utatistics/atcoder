#include <bits/stdc++.h>

using ll = long long;

int main() {
    std::string s;
    std::cin >> s;

    int N = (int)s.size();
    
    std::map<char, int> m;
    for (int i = 0; i < N; i++) m[s[i]]++;

    ll ans = 1LL * N * (N - 1) / 2;
    bool flg = false;
    for (auto [c, cnt] : m) {
        ans -= 1LL * cnt * (cnt - 1) / 2;
        if (cnt > 1) flg = true;
    }
    
    if (flg) ++ans;
    std::cout << ans << std::endl;
    return 0;
}

