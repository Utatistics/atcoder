#include <bits/stdc++.h>

int main() {
    // input
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    // solve
    int ans = N + 1;
    int r = 0;
    int dup = 0; // duplicate counter
    std::map<int, int> m;
    for (int l = 0; l < N; l++) {
        while (r < N && dup == 0) { // monotonically increasing
            m[A[r]]++; 
            if (m[A[r]] == 2) dup++;
            r++;
        }
        if (dup > 0) ans = std::min(ans, r - l); // update ans

        m[A[l]]--;
        if (m[A[l]] == 1) dup--;
    }

    // presentation
    if (ans == N + 1) ans = -1;
    std::cout << ans << std::endl;

    return 0;
}
