#include <bits/stdc++.h>

auto solve (const std::vector<int> &A) {
    int N = A.size();
    std::vector<int> C(N); // count freq at index
    std::vector<bool> V(N, false);

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (V[A[i] - 1] == false) {
            V[A[i] - 1] = true;
            cnt++;
        }
        C[i] = cnt;
    }

    return C;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    // solve
    std::vector<int> L = solve(A);    
    std::reverse(A.begin(), A.end());
    std::vector<int> R = solve(A);

    // presentation
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans = std::max(ans, L[i] + R[(N - 1) - i - 1]);
    }

    std::cout << ans << std::endl;
    return 0;
}

