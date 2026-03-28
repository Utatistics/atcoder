#include <bits/stdc++.h>

using ll = long long;
using T = std::tuple<int, int, int>;

int mod(int a, int b) {return (a % b + b) % b;}

int main () {
    // input processing
    int N;
    std::cin >> N;  

    std::vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] = mod(A[i], 46);
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
        B[i] = mod(B[i], 46);
    }
    for (int i = 0; i < N; i++) {
        std::cin >> C[i];
        C[i] = mod(C[i], 46);
    }
    
    // solve
    std::vector<T> b; // possible petters via brute-force
    for (int i = 0; i < 46; i++) {
        for (int j = 0; j < 46; j++) {
            for (int k = 0; k < 46; k++) {
                if (mod(i + j + k, 46) == 0)
                    b.push_back({i, j, k});
            }
        }
    }

    std::vector<int> ca(46), cb(46), cc(46);
    for (int i = 0; i < N; i++) {// count if included
        ca[A[i]]++;
        cb[B[i]]++;
        cc[C[i]]++;
    }
    
    // presentation
    ll ans = 0;
    for (T p : b) { // pettern
        auto [a, b, c] = p;
        ans += 1LL * ca[a] * cb[b] * cc[c];
    }

    std::cout << ans << std::endl;

    return 0;
}
