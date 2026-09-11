#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    std::sort(A.begin(), A.end());
    
    int ans = 0;

    int r = 0; // right ptr
    for (int l = 0; l < N; l++) { // left ptr
        while (r < N && A[r] - A[l] < M) { // monotonically increasing
            r++;
        }
        ans = std::max(ans, r - l); // update ans
        if (l == r) ++r;
    }
    
    std::cout << ans << std::endl;
    return 0;
}

