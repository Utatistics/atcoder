#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(2 * N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i + N] = A[i];
    }

    std::vector<int> ps(2 * N + 1, 0);
    for (int i = 1; i <= 2 * N; i++) {
        ps[i] = (ps[i - 1] + A[i - 1]) % M;
    }

    std::vector<int> cnt(M, 0);
    for (int i = 1; i < N; i++) {
        cnt[ps[i]]++;
    }

    ll ans = cnt[ps[0]];
    for (int s = 1; s < N; s++) {
        cnt[ps[s]]--;
        cnt[ps[s + N - 1]]++;

        ans += cnt[ps[s]];
    }

    std::cout << ans << '\n';
}
