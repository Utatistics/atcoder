#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    bool ans = true;

    ll a, b, c;
    std::cin >> a;
    std::cin >> b;

    for (int i = 2; i < N; i++) {
        std::cin >> c;

        if (b * b != a * c) {
            ans = false;
            break;
        }

        a = b;
        b = c;
    }

    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}
