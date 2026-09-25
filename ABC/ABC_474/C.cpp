#include <bits/stdc++.h>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> P(N);
    std::vector<int> m(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
        --P[i];
        m[P[i]] = i;
    }
    std::vector<int> A(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> A[i];
        --A[i];
    }

    std::vector<bool> v(N, false);
    std::vector<int> a;
    for (auto it = A.rbegin(); it != A.rend(); ++it) {
        int i = m[*it];
        if (v[i]) continue;
        a.push_back(*it);
        v[i] = true;
    }

    for (int i = 0; i < N; i++) {
        if (v[i]) continue;
        std::cout << P[i] + 1 << " ";
    }
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        std::cout << *it + 1 << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

