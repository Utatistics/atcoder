#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    
    std::vector<int> ps(N, 0);
    for (int i = 1; i <= N; i++) {
        if (i % 2 != 0) {
            ps[i] = ps[i - 1];
        }
        else {
            ps[i] = ps[i - 1] + (A[i] - A[i - 1]);           
        }
    }
   
    int Q;
    std::cin >> Q;

    while (Q--) {
        ll ans = 0;

        int l, r;
        std::cin >> l >> r;

        auto left = std::lower_bound(A.begin(), A.end(), l) - A.begin();
        auto right = std::lower_bound(A.begin(), A.end(), r) - A.begin();

        if (left % 2 == 0) ans += A[left] - l;
        if (right % 2 == 0) ans += r - A[right - 1];
        ans += ps[right - 1] - ps[left];

        std::cout << ans << "\n";
    }
    return 0;
}

