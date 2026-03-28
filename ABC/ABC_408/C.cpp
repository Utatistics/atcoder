#include <bits/stdc++.h>

int main() {
    // input
    int N, M;
    std::cin >> N >> M;

    // solve
    std::vector<int> imos(N + 1, 0);
    for (int i = 0; i < M; i++) { // 1dim imos
        int l, r;
        std::cin >> l >> r;
        l--; r--; // 0 index
        imos[l]++;
        imos[r + 1]--;
    }

    std::vector<int> A(N + 1);
    for (int i = 0; i < N; i++)
        A[i] = (i == 0) ? imos[i] : A[i - 1] + imos[i];

    int ans = M;
    for (int i = 0; i < N; i++) {
        ans = std::min(ans, A[i]);
    }

    // presentation
    std::cout << ans << std::endl;
    
    return 0;
}

