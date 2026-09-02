#include <bits/stdc++.h>

using ll = long long;

int main() {
    int a, b;
    ll C;
    std::cin >> a >> b >> C;

    int N = 60;
    int p = __builtin_popcountll(C); // num of 1s in C 
    int q = N - p;                 // num of 0s in C

    ll d = a + b - p; // d of 1s, needs to be filled with {1, 1}
    if (d < 0) { // p too small to create a + b of 1s
        std::cout << -1 << std::endl;
        return 0;
    }
    if (d%2 == 1) { // d needs to be filled with {1, 1} *not {1, 0} or {0, 1}
        std::cout << -1 << std::endl;
        return 0;
    }

    d /= 2; // num of columns to be used on {1, 1} side
    a -= d; // remaining 1s in x, on {1, 0} or {0, 1} side
    b -= d; // remaining 1s in y, on {1, 0} or {0, 1} side
    if (d > q || a < 0 || b < 0) { // a and/or b is too small for p
        std::cout << -1 << std::endl;
        return 0;
    }
    
    std::vector<int> X(N), Y(N);
    std::vector<int> i0, i1;
    for (int i = 0; i < N; i++) {
        if (C >> i&1) i1.push_back(i); // index at 2^i = 1
        else i0.push_back(i); // at 2^i = 0
    }

    for (int j = 0; j < d; j++) { // filling with {1, 1}
      int i = i0[j];
      X[i] = Y[i] = 1;
    }
    for (int j = 0; j < p; j++) { // filling with {1, 0} or {0, 1}
        int i = i1[j];
        if (j < a) X[i] = 1; // first fill a of 1s
        else Y[i] = 1; // then b of 1s
    }
    
    auto f = [&](const std::vector<int>& v) -> ll {
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            ans |= (ll)v[i]<<i;
        }
        return ans;
    };

    std::cout << f(X) << ' ' << f(Y) << std::endl;
}
