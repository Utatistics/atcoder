#include <bits/stdc++.h>

int main() {
    int M, D;
    std::cin >> M >> D;
    
    std::string S;
    std::cin >> S;

    std::vector<bool> C(M, false);

    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (S[i] == 'G') {
            int l = i;
            C[i] = true;
            while (l - 1 >= 0 && i - l < D) {
                --l;
                C[l] = true;
            }
            int r = i;
            while (r + 1 < M && r - i < D) {
                ++r;
                C[r] = true;
            }
        }
    }

    int ans = M;
    for (auto c : C) if (c) --ans;
    std::cout << ans << std::endl;
    return 0;
}
