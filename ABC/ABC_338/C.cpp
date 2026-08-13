#include <bits/stdc++.h>

static constexpr int MAX = 1e6;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> Q(N), A(N), B(N);
    for (int &q : Q) std::cin >> q;
    for (int &a : A) std::cin >> a;
    for (int &b : B) std::cin >> b;

    int ma = MAX;
    for (int i = 0; i < N; i++) {
        if (A[i] > 0)
            ma = std::min(ma, Q[i] / A[i]);
    }

    int ans = 0;
    for (int a = 0; a <= ma; a++) { // O(A) ~10^6
        int b = MAX;

        for (int i = 0; i < N; i++) { // O(N) ~10^1 
            if (B[i] > 0)
                b = std::min(b, (Q[i] - A[i] * a) / B[i]);
        }
        ans = std::max(ans, a + b);
    }

    std::cout << ans << '\n';
}
