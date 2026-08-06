#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N), I(N + 1, -1);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        I[A[i]] = i; // val 2 idx
    }

    int K = 0;
    std::vector<P> ans;
    for (int i = 0; i < N; i++) {
        int j = I[i + 1];
        if (i == j) continue; // no swap needed

        std::swap(A[i], A[j]);
        std::swap(I[A[i]], I[A[j]]); // update index after swap

        ++K;
        ans.emplace_back(i + 1, j + 1);
    }

    std::cout << K << std::endl;
    for (auto [i, j] : ans)
        std::cout << i << " " << j << "\n";
    

    return 0;
}

