#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;
    
    std::string S;
    std::cin >> S;

    std::vector<int> cnt(10, 0);
    for (int i = 0; i < N; i++) cnt[(int)(S[i] - '0')]++;
    ll M = std::pow(10, N);
    
    auto f = [&](int x) -> bool {
        bool res = true;
        ll sq = 1LL * x * x;
        std::vector<int> m(10, 0);
        
        int c = N;
        while(sq > 0 && c--) {
            m[sq % 10]++;
            sq /= 10;
        }
        for (int i = 0; i < c; i++) m[0]++;

        for (int i = 0; i < 10; i++) { 
            if (cnt[i] != m[i]) res = false;
            if (!res) break;
        }
        
        return res;
    };

    int ans = 0;
    for (int x = 0; 1LL * x * x < M; x++) {
        if (f(x)) ++ans;
    }
    std::cout << ans << std::endl;

    return 0;
}

