#include <bits/stdc++.h>

using ll = long long;

ll mod(ll a, ll b) { return (a % b + b) % b; }

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> D(11); // 0 - 10 digits
    for (int i = 0; i < N; i++) {
        int d = std::to_string(A[i]).size();
        D[d].push_back(A[i]);
    }

    ll ans = 0;
    ll base = 1; // 1 ^^ b
    for (int b = 0; b < 11; b++) {
        std::unordered_map<int, int> m;
        for (int a : D[b]) m[a % M]++; // Aj mod M
        for (int i = 0; i < N; i++) { // find Aj ≡ −Ai⋅10b (modM)
            ll r = mod(-base * A[i], M); // −Ai⋅10b mod M
            ans += m[r];
        }
        base *= 10; base %= M;
    }

    std::cout << ans << std::endl;

    return 0;
}

