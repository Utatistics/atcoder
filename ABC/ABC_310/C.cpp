#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) std::cin >> S[i];
   
    int ans = 0;
    std::set<std::string> s;
    for (int i = 0; i < N; i++) {
        std::string str = S[i];
        std::string rstr(str.rbegin(), str.rend());

        if (s.count(str) + s.count(rstr) == 0) ++ans;
        s.insert(str);
        s.insert(rstr);
    }

    std::cout << ans << std::endl;
    return 0;
}
