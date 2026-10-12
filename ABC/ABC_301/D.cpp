#include <bits/stdc++.h>

using ll = long long;

int main() {
    std::string S;
    std::cin >> S;

    ll N;
    std::cin >> N;

    auto toBase10 = [&](const std::string& s, int b) -> ll {
        ll d = 0;
        for (char c : s) d = d * b + (c - '0');

        return d;
    };

    auto T = S;
    for (char& c : T) {
        if (c == '?') c = '0';
    }

    if (toBase10(T, 2) > N) {
        std::cout << -1 << std::endl;
        return 0;
    }

    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] != '?') continue;

        T[i] = '1';
        if (toBase10(T, 2) > N) {
            T[i] = '0';
        }
    }

    std::cout << toBase10(T, 2) << std::endl;

    return 0;
}
