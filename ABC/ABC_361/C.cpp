#include <bits/stdc++.h>

using ll = long long;

static const ll MAX = 1e9 + 9;

int main() {
    int N, K;
    std::cin >> N >> K;
 
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    std::sort(A.begin(), A.end());

    ll ans = MAX;

    ll diff = 0;
    int l = 0, r = 0;
    while (r < N - 1) {
        for (; r - l < N - K - 1; r++) { // cumurative diff for window
            diff += A[r + 1] - A[r];
        }
        
        ans = std::min(ans, diff);
        diff -= A[l + 1] - A[l];
        ++l; // slide window
    }

    std::cout << ans << std::endl;
    return 0;
}

