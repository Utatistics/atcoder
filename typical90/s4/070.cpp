#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i] >> Y[i];
    }

    std::sort(X.begin(), X.end());
    std::sort(Y.begin(), Y.end());

    ll a = X[N / 2];
    ll b = Y[N / 2];

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += std::abs(X[i] - a);
        ans += std::abs(Y[i] - b);
    }

    std::cout << ans << std::endl;
    return 0;
}

