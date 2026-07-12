#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    ll S;
    std::cin >> S;

    std::vector<int> A(2 * N);
    ll T = 0;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        A[i] = a; A[i + N] = a;
        T += a;
    }

    bool ans = false;

    ll mod = S % T;
    int r = 0;
    ll s = 0;
    for (int l = 0; l < N; l++) { // left ptr
        while (r < 2 * N && s < mod) {
            s += A[r];
            r++;
        }
        if (!ans && s == mod) ans = true;
        if (l == r) ++r;
        s -= A[l];
    }
    
    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";
    
    return 0;
}

