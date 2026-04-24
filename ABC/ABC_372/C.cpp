#include <bits/stdc++.h>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::string S;
    std::cin >> S;

    auto is_abc = [&](int i) {
        if (i < 0 || i + 2 >= N) return false;
        return S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C';
    };

    int ans = 0;
    for (int i = 0; i + 2 < N; i++) { // O(9)
        if (is_abc(i)) ans++;
    }

    while (Q--) {
        int X;
        char C;
        std::cin >> X >> C;
        X--; // 1-index → 0-index

        if (C == S[X]) {
            std::cout << ans << "\n";
            continue;
        }

        for (int i = X - 2; i <= X; i++) {
            if (is_abc(i)) ans--;
        }
        
        S[X] = C; // update

        for (int i = X - 2; i <= X; i++) {
            if (is_abc(i)) ans++;
        }

        std::cout << ans << "\n";
    }

    return 0;
}
