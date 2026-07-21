#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<int, int>;

int main() {
    int N;
    std::cin >> N;

    std::vector<P> A;
    for (int i = 0; i < N; i++) {
        int l, r;
        std::cin >> l >> r;
        A.push_back({l, r});
    }
    std::sort(A.begin(), A.end());

    auto binarySearch = [&](int i) -> int {
        int left = i - 1;
        int right = N;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (A[i].second < A[mid].first) right = mid;
            else left = mid;
        }
        return right;
    };

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int j = binarySearch(i);
        ans += j - i - 1;
    }

    std::cout << ans << std::endl;

    return 0;
}
