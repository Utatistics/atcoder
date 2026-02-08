#include <bits/stdc++.h>

using ll = long long;
static const ll MOD = 1e9 + 7;

int main () {
    // input processing
    int N;
    std::cin >> N;

    // solve
    std::vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            int a;
            std::cin >> a;
            A[i] += a;
        }
    }

    ll ans = 1;
    for (int i = 0; i < N; i++)
        ans = (ans * A[i]) % MOD;
    

    // presentation
    std::cout << ans << std::endl;
}
