#include <bits/stdc++.h>

using ll = long long;

int main() {
    ll X, Y;
    std::cin >> X >> Y;

    std::vector<ll> A;
    A.push_back(X); // init
    while (A.back() <= Y) {
        ll a = A.back();
        if (a * 2LL <= Y) A.push_back(a * 2LL);
        else break;
    }

    std::cout << (int)A.size() << std::endl;
    return 0;
}

