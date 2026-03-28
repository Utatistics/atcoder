#include <bits/stdc++.h>

int main() {
    // input
    int N;
    std::cin >> N;

    std::vector<int> A, c(N, 0);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;

        if (c[a  - 1] == 0) A.push_back(a);
        c[a - 1]++;
    };
        
    // solve
    int ans = 0;
    
    std::sort(A.begin(), A.end()); // O(N * logN)
     
    int M = A.size();
    int r = 0;
    int len = 0;
    for (int l = 0; l < M; l++) {
        while (r < M) { // monotonically increasing
            if (l != r && A[r] - A[r - 1] != 1) break;
            else if (l != r && A[r] - A[r - 1] == 1) len++;
            r++;
        }

        ans = std::max(ans, len);

        if (r == l) ++r;
        else len--; // prepare 'l' to move forward
    }

    // presentation
    std::cout << ans << std::endl;

    return 0;
}
