#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<ll> A(N + 1), B(N + 1), C(N + 1);

    for (int i = 1; i <= N; i++) std::cin >> A[i];
    for (int i = 1; i <= N; i++) std::cin >> B[i];
    for (int i = 1; i <= N; i++) std::cin >> C[i];

    std::vector<ll> PA(N + 1), PB(N + 1), PC(N + 1);

    for (int i = 1; i <= N; i++) {
        PA[i] = PA[i - 1] + A[i];
        PB[i] = PB[i - 1] + B[i];
        PC[i] = PC[i - 1] + C[i];
    }

    // S = (PA[x] - PB[x]) + (PB[y] - PC[y])  + Const (i.e. C[N])
    
    ll a = PA[1] - PB[1]; // x = 1 (i.e. y = 2)
    ll ans = 0;
    for (int y = 2; y <= N - 1; y++) {
        ans = std::max(ans, a + (PB[y] - PC[y]));
        a = std::max(a, PA[y] - PB[y]); // y = next valid x
    }

    ans += PC[N];

    std::cout << ans << std::endl;
}
