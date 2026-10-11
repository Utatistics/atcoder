#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    ll W;
    std::cin >> N >> W;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        std::cin >> B[i];
    }

    ll ans = 0;
    for (int i = 0; i < (1LL << N); i++) { // subset 0 to 2^N - 1 
        
        ll a = 0; ll b = 0;
        for (int j = 0; j < N; j++) { // checking jth bit of given i
            if (i & (1 << j)) {
                a += A[j];
                b += B[j];
            }
        }
        if (b > W) continue;
        ans = std::max(ans, a);
    }

    std::cout << ans << std::endl;
    
    return 0;
}

