#include <bits/stdc++.h>

int main() {
    int Q;
    std::cin >> Q;

    std::string S, T;
    std::cin >> S >> T;

    int N = (int)S.size();
    int M = (int)T.size();

    std::vector<int> v; // index set
    for (int i = 0; i < N; i++) {
        if (S[i] != T[0]) continue;

        bool flg = true;
        for (int j = 0; j < M && i + j < N; j++) {
            if (S[i + j] != T[j]) flg = false;
        }
        if (flg) v.push_back(i);
    }

    while (Q--) {
        int l, r ;
        std::cin >> l >> r;
        --l; --r;

        auto it = std::lower_bound(v.begin(), v.end(), l);
        // std::cout << *it << std::endl;

        if (it == v.end()) {
            std::cout << "No\n";
        }
        else if (r - *it + 1 < M) {
            std::cout << "No\n";
        }
        else {
            std::cout << "Yes\n";
        }
    }
    return 0;
}

