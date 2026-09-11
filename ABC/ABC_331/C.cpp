#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    ll s = 0;
    std::map<int, int> cnt;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        cnt[A[i]]++;
        s += A[i];
    }

    std::map<int, ll> m;
    for (auto [a, c] : cnt) {
        m[a] = s - 1LL * a * c;
        s -= a * c;
    }

    for (int i = 0; i < N; i++) std::cout << m[A[i]] << " ";
    std::cout << std::endl;

    return 0;
}

