#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N;
    std::string S;

    std::cin >> N >> S;

    bool ans = false;

    int x = 0, y = 0;
    std::set<P> s;
    s.emplace(x, y);

    for (char c : S) {
        if (c == 'R') ++x;
        else if (c == 'L') --x;
        else if (c == 'U') ++y;
        else --y;

        P p = {x, y};
        if (s.count(p) > 0) {
            ans = true;
        }
        s.insert(p);
    }

    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

