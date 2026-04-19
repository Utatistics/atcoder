#include <bits/stdc++.h>

using ll = long long;

ll solve(ll l, ll r) { // count x ∈[l,r] s.t. |x| is even
    l += 1e7; // shift to positive
    r += 1e7;
    if (r % 2) r--; // if odd
    if (l % 2) l--; 

    if(l > r) return 0;
    return (r - l) / 2 + 1;
}

int main() {
    ll L, R, D, U;
    std::cin >> L >> R >> D >> U;

    ll ans = 0;
    for (ll y = D; y <= U; y++) {
        ll v = std::abs(y); // |y|
        
        // black if max(|x|, |y|) is even, but given v...
        // case 1. if ∣x∣ >= v, then |x| is even -> color alternates
        // case 2. if ∣x∣ <  v, then  v  is even -> all same color

        ans += solve(L, R); // assume all to be case 1.
                        
        ll l2 = std::max(L, v);
        ll r2 = std::min(R, v);
        if (nl <= nr) { // substruct 
            ans -= solve(l2, r2);
            if (v % 2 == 0) ans += r2 - l2 + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

