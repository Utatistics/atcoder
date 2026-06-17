#include <bits/stdc++.h>

using tup = std::tuple<int, int, std::string>;

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<tup> qs;
    for (int i = 0; i < Q; i++) {
        int t, p;
        std::string s;
        std::cin >> t >> p;
        if (t == 2) std::cin >> s;
        qs.push_back({t, p, s});
    }

    int a = 0;
    std::vector<std::string> buf;
    for (int i = Q - 1; i >= 0; i--) { // backward
        auto [t, p, s] = qs[i];
        if (a == 0) { // track server
            if (t == 3) a = p;
            else continue;
        }
        else { // track node
            if (p != a) continue;

            if (t == 1) a = 0;
            else if (t == 2) buf.push_back(s);
            else continue;
        }
    }

    std::string ans = "";
    int M = buf.size();
    for (int i = M - 1; i >= 0; i--) ans += buf[i];
    std::cout << ans << std::endl;

    return 0;
}

