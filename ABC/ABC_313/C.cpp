#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    ll sum = 0;

    for (int& a : A) {
        std::cin >> a;
        sum += a;
    }

    ll lt = sum / N; // floor(avg)
    ll ut = (sum + N - 1) / N; // ceil(avg)

    ll l = 0;
    ll u = 0;

    for (auto a : A) {
        if (a < lt) l += lt - a;
        if (a > ut) u += a - ut;
    }

    std::cout << std::max(l, u) << '\n';
}
