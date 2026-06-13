#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::string T;
    std::cin >> T;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = (T[i] == '0');
    }

    std::vector<int> ps(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        ps[i] = A[i - 1] + ps[i - 1];
    }
    for (int i = 0; i <= N; i++) {
        ps[i] %= 2;
    }

    std::vector<int> cnt(2); // 0 and 1
    for (int i = 0; i <= N; i++) {
        cnt[ps[i]]++;
    }
    
    ll ans = 0;
    ans += 1LL * cnt[0] * (cnt[0] -1) / 2;
    ans += 1LL * cnt[1] * (cnt[1] -1) / 2;

    std::cout << ans << std::endl;

    return 0;
}

