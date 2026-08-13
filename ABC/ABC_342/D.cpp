#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;

        for (int x = 2; x * x <= a; x++) {
            if (a % (x * x) != 0) continue;
            while (a % (x * x) == 0 && a >= x * x) {
                a /= x * x;
            }
        }
        A[i] = a;
    }
    
    ll ans = 0;

    std::map<int, int> m;
    for (int i = 0; i < N; i++) m[A[i]]++;
    for (auto [b, c] : m) {
        if (b == 0) {
            ans += 1LL * c * (N - c);
        }
        ans += 1LL * c * (c - 1) / 2;
    }

    std::cout << ans << std::endl;
    return 0;
}

