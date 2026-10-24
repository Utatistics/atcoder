#include <bits/stdc++.h>

int main() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> A(N);
    std::map<int, int> m;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        m[A[i]]++;
    }

    bool ans = false;
    for (int i = 0; i < N; i++) {
        if (m[A[i]+ X] > 0) ans = true;
        if (m[A[i]- X] > 0) ans = true;
    }

    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

