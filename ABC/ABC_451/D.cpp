#include <bits/stdc++.h>

static const int MAX = 1e9;

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> P;
    for (int p = 1;  p <= MAX; p *= 2) P.push_back(std::to_string(p));

    std::set<int> S;
    auto dfs = [&](auto dfs, std::string s0) -> void {
        for (std::string p : P) {
            std::string s1 = s0 + p;
            if (s1.size() > 9) break;
            S.insert(std::stoi(s1));
            dfs(dfs, s1);
        }
    };
    dfs(dfs, "");

    auto it = S.begin();
    std::advance(it, N - 1); // 0 index
    std::cout << *it << std::endl;

    return 0;
}

