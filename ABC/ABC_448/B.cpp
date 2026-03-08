#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> C(M);
    for (int i = 0; i < M; i++) std::cin >> C[i];

    std::vector<int> salt(M, 0);
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        
        salt[a] += b;
    }

    // presentation
    ll ans = 0;
    for (int i = 0; i < M; i++)
        ans += (salt[i] > C[i]) ? C[i] : salt[i];
    
    std::cout << ans << std::endl;

    return 0;
}
