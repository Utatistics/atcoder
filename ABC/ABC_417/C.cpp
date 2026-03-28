#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input processing
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    // solve
    std::unordered_map<ll, int> m;
    ll ans = 0;

    for (int j = 0; j < N; j++) {
        ans += m[j - A[j]]; // fixed sign and order
        m[j + A[j]]++;  // insert after counting (enforces i < j)
    }

    // presentation
    std::cout << ans << std::endl;
    return 0;
}

