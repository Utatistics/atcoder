#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    int ans = 0;
    auto f = [&](int i, int j) {
        std::vector<int> cnt(N + 1, 0);
        int r = i; // right ptr
        for (int l = i; l < j; l += 2) { // left ptr
            while (r < j && A[r] == A[r + 1] && cnt[A[r]] == 0) {
                cnt[A[r]]++;
                r += 2;
            }

            ans = std::max(ans, r - l);

            if (l == r) r += 2;
            else cnt[A[l]]--;
        }
    };

    f(0, N);
    f(1, N - 1);

    std::cout << ans << std::endl;

    return 0;
}
