#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> R(N);
    for (int i = 0; i < N; i++) std::cin >> R[i];
    
    std::vector<int> A;

    auto dfs = [&](auto f, int s) -> void {
        if (A.size() == R.size()) {
            if (s % K == 0) {
                for (int i = 0; i < (int)A.size(); i++) std::cout << A[i] << " ";
                std::cout << "\n";
            }
            return;
        }

        for (int r = 1; r <= R[(int)A.size()]; r++) {
            A.push_back(r);
            f(f, s + r);
            A.pop_back();
        }
    };
    
    dfs(dfs, 0);

    return 0;
}
