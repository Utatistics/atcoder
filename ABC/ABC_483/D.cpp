#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<ll> A(N);
    for (auto& a : A) std::cin >> a;

    std::vector<ll> L(N), R(N);
    ll l = 0, r = 0;
    for (int i = N - 1; i >= 0; i--) {
        L[i] = l; 
        R[i] = r; 

        l += A[i]; r += A[i]; // the edges shifted
        l = std::min(l, 0LL); r = std::max(r, 0LL);
        std::cout << l << "&" << r << std::endl;
    }

    ll ans = r - l;
    
    l = r = 0;
    ll x = 0; // current position
    for (int i = 0; i < N; i++) {
        { // flipping A[i]
            ll nl = L[i], nr = R[i];
            nl += x - A[i]; nr += x - A[i]; // flip
            
            ll d = std::max(nr, r) - std::min(nl, l);
            ans = std::max(ans, d);
        }

        x += A[i]; // position update
        l = std::min(l, x); r = std::max(r, x);
    }
    std::cout << ans + 1 << '\n';

    return 0;
}
