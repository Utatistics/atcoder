#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> R(N, -1); // r = R[c] contains rock in column c 
    std::vector<int> C(N, -1); // c = C[r] contains rock in row r

    int ans = 0;
    auto rm = [&](int r, int c) { 
        R[c] = C[r] = -1;
        --ans;
    };

    for (int i = 0; i < M; i++) {
        int r, c;
        std::cin >> r >> c;
        --r; --c;

        if (R[c] != -1) rm(R[c], c);
        if (C[r] != -1) rm(r, C[r]);
        
        R[c] = r;
        C[r] = c;
        ++ans;
    }

    std::cout << ans << std::endl;

    return 0;
}

