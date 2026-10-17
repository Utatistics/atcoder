#include <bits/stdc++.h>

using ll = long long;

int main() {
    std::string S;
    std::cin >> S;

    ll ans = 0;
    
    auto sol1 = [&]() -> void {        
        int p = 0; // parity state bit (e.g.'2023'->0000001201->1001->9)
        std::vector<ll> cnt(1024, 0); // cnt for possible states (2^10)
        cnt[0] = 1;

        for (char c : S) { // O(N)
            p ^= (1 << (c - '0')); // flipping the single bit for 'c'
            ans += cnt[p];  
            cnt[p]++; // append parity state
        }
    };

    auto sol2 = [&]() -> void {        
        std::map<std::vector<int>, ll> m;
        std::vector<int> A(10, 0);
        
        m[A] = 1;
        for (char c : S) {
            // A[c - '0'] ^= 1; // swich parity
            A[c - '0'] = (A[c - '0'] + 1) % 2;
            ans += m[A];
            m[A]++;
        }
    };
    
    sol1();
    // sol2();

    std::cout << ans << std::endl;

    return 0;
}

