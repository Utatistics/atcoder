#include <bits/stdc++.h>

using ll = long long;

static const int MOD = 1e8;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += 1LL * A[i] * (N - 1);
    }

    auto binarySearch = [&](int i) -> int {
        int l = i;
        int r = N;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (A[i] + A[mid] >= MOD) r = mid;
            else l = mid;
        }
        return r;
    };    

    for (int i = 0; i < N - 1; i++) {
        int j = binarySearch(i);
        ans -= 1LL * (N - j) * MOD;
    }

    std::cout << ans << std::endl;
    return 0;
}

