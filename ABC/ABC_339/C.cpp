#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    ll s = 0; 
    std::vector<ll> ps(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        ps[i] = ps[i - 1] + A[i - 1];
        if (ps[i] < 0) s = std::max(s, std::abs(ps[i]));
    }

    std::cout << s + ps[N] << std::endl;
    return 0;
}

