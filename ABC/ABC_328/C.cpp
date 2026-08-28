#include <bits/stdc++.h>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::string S;
    std::cin >> S;

    std::vector<int> pref(N, 0);
    for (int i = 1; i < N; i++) {
        pref[i] = pref[i - 1] + (S[i] == S[i - 1]);
    }

    while (Q--) {
        int l, r;
        std::cin >> l >> r;
        --l; --r;
        std::cout << pref[r] - pref[l] << '\n';
    }

    return 0;
}
