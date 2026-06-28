#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<int, int>;

int main() {
    int N, M;
    std::cin >> N >> M;

    ll ans = 1LL * M * (M - 1) / 2;
    std::map<int, int> cnt;
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        --a; --b;
        cnt[(a + b) % N]++;
    }
    
    for (auto [k, c] : cnt) 
        ans -= 1LL * c * (c - 1) / 2;
    
    std::cout << ans << std::endl;

    return 0;
}

