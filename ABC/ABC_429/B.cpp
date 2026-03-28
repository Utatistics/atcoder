#include <bits/stdc++.h>

int main() {
    // input processing
    int N, M;
    std::cin >> N >> M;

    int s = 0;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        s += A[i];
    }

    // solve
    std::string ans = "No";
    for (int i = 0; i < N; i++) {
        if (s - A[i] == M) {
            ans = "Yes";
            break;
        }
    }

    // presentation
    std::cout << ans << std::endl;
    
    return 0;
}

