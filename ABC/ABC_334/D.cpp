#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> R(N);
    for (int i = 0; i < N; i++) std::cin >> R[i];
    std::sort(R.begin(), R.end());

    std::vector<ll> ps(N + 1, 0);
    for (int i = 1; i <= N; i++) ps[i] = ps[i - 1] + R[i - 1];
    
    auto binarySearch = [&](ll k) -> int {
        int l = -1;
        int r = N + 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (ps[mid] > k) r = mid;
            else l = mid;
        }
        return l;
    };

    while (Q--) {
        ll x;
        std::cin >> x;

        int k = binarySearch(x);
        if (k < 0) k = 0; // edge case
        std::cout << k << "\n";
    }
    return 0;
}

