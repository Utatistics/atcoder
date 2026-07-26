#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    int ans = 0;
    for (int i = 1; i < N - 1; i++) {
        if (A[i - 1] < A[i] && A[i] > A[i + 1])
            ++ans;
    }

    std::cout << ans << std::endl;
    return 0;
}
