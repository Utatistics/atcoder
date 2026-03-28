#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    // solve
    std::vector<ll> ps(N);
    for (int i = 0; i < N; i++)
        ps[i] = (i == 0) ? A[i] : ps[i - 1] + A[i];
    
    ll ans = 0;
    for (int i = 0; i < N; i++)
        ans += A[i] * (ps[N - 1] - ps[i]);
    
    std::cout << ans << std::endl;

    return 0;
}

