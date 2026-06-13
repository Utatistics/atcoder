#include <bits/stdc++.h>

using ll = long long;
static const int MAX = 1e6;

int main() {
    int N, D;
    std::cin >> N >> D;

    std::vector<int> imos(MAX + 1, 0);
    for (int i = 0; i < N; i++) { // O(MAX)
        int s , t;
        std::cin >> s >> t;
        --s; --t;
        if (t - s < D) continue;
        imos[s]++;
        imos[t - D + 1]--;
    }

    std::vector<int> A(MAX + 1); 
    for (int i = 0; i <= MAX; i++) // O(MAX)
        A[i] = (i == 0) ? imos[i] : A[i - 1] + imos[i];

    ll ans = 0;
    for (int i = 0; i < MAX; i++) { // O(MAX)
        ans += 1LL * A[i] * (A[i] - 1) / 2;
    }

    std::cout << ans << std::endl;
    return 0;
}

