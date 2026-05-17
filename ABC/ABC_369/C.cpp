#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    if (N == 1) { // edgw case
        std::cout << 1 << '\n';
        return 0;
    }

    ll ans = 0;
    int r = 1;
    for (int l = 0; l < N; l++) {
        int d = A[r] - A[r - 1];
        while (r + 1 < N && d == A[r + 1] - A[r]) {
            r++;
        }
        ans += (r - l) + 1;
        if (r - l == 1 && r < N - 1) r++;
    }

    std::cout << ans << std::endl;
    return 0;
}

