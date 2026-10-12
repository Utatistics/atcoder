#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) std::cin >> S[i];

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) A[i] = i;

    bool ans = false;

    do { // A needs to be sorted
        int cnt0 = 0;
        for (int i = 0; i < N - 1; i++) {
            int cnt1 = 0;
            for (int j = 0; j < M; j++) {
                if (S[A[i]][j] != S[A[i + 1]][j]) ++cnt1;
            }
            if (cnt1 == 1) ++cnt0;
        }
        if (cnt0 == N - 1) ans = true;

    } while (std::next_permutation(A.begin(), A.end()));

    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

