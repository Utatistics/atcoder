#include <bits/stdc++.h>

using ll = long long;

int main() {
    int K;
    std::cin >> K;
    --K;

    std::vector<std::vector<int>> A;
    auto dfs = [&](auto f, auto& v) -> void {
        A.push_back(v);
        // for (int x : v) std::cout << x;
        // std::cout << std::endl;

        if (v.back() == 0) {
            return;
        }

        for (int i = v.back() - 1; 0 <= i; i--) {
            v.push_back(i);
            f(f, v);
            v.pop_back();
        }
    };

    for (int i = 1; i <= 9; i++) {
        std::vector<int> u(1, i);
        dfs(dfs, u);
    }

    std::vector<ll> ans;
    for (auto u : A) {
        std::string s = "";
        for (int x : u) {
            s += x + '0';
        }
        ans.push_back(std::stol(s));
    }
    std::sort(ans.begin(), ans.end());
    std::cout << ans[K] << std::endl;

    return 0;
}


