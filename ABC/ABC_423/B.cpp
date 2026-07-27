#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> L(N);
    for (int i = 0; i < N; i++) std::cin >> L[i];    
    
    std::vector<int> v(N + 1, 0);
    v[0] = 1;
    for (int i = 0; i < N; i++) {
        if (L[i] != 0) break;
        if (v[i + 1] > 0) break;
        else v[i + 1]++;
    }
    v[N] = 1;
    for (int i = N - 1; i >= 0; i--) {
        if (L[i] != 0) break;
        if (v[i] > 0) break;
        else v[i]++;
    }

    int ans = N + 1;
    for (int i = 0; i <= N; i++) ans -= v[i];
    
    std::cout << ans << std::endl;

    return 0;
}

