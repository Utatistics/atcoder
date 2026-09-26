#include <bits/stdc++.h>

int main() {
    int N, D;
    std::cin >> N >> D;

    std::vector<int> X(N);
    for (int i = 0; i < N; i++) std::cin >> X[i];

    std::vector<int> ans;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (std::abs(X[i] - X[j]) >= D) {
                ++cnt;
            }
        }
        if (cnt == N - 1) {
            ans.push_back(i + 1);
        }
    }

    std::cout << (int)ans.size() << std::endl;
    for (auto x : ans) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}

