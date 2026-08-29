#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A;
    auto dfs = [&](auto f, int i, int r) -> void {
        if (i == N) {
            if (r == 0) {
                for (auto a : A) std::cout << a << " ";
                std::cout << "\n";
            }
            return;
        }
        int w = i + 1; // 0 to 1 origin
        for (int x = 0; x * w <= r; x++) {
            A.push_back(x);
            f(f, i + 1, r - x * w);
            A.pop_back();
        }
    };
    dfs(dfs, 0, K);

    return 0;
}
