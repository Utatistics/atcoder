#include <bits/stdc++.h>

using ll = long long;
using tup = std::tuple<ll, ll, int>;

int main() {
    int N;
    std::cin >> N;

    std::vector<tup> ans;
    for (int i = 0; i < N; i++) {
        ll a, b;
        std::cin >> a >> b;
        ans.emplace_back(a, b, i + 1);
    }
    auto comp = [](auto const& p, auto const& q) {
        auto [a0, b0, i0] = p;
        auto [a1, b1, i1] = q;

        ll lhs = a0 * (a1 + b1);
        ll rhs = a1 * (a0 + b0);

        if (lhs != rhs) return lhs > rhs;
        else return i0 < i1;
    };
    std::sort(ans.begin(), ans.end(), comp);    
    
    for (auto [a, b, i] : ans) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
