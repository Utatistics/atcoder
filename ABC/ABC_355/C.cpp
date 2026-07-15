#include <bits/stdc++.h>

int main() {
    int N, T;
    std::cin >> N >> T;

    
    int ans = -1;
    std::vector<int> R(N, 0);
    std::vector<int> C(N, 0);
    int d0 = 0; // diag top left to bottom right
    int d1 = 0; // diag bottom left to to right
    for (int i = 0; i < T; i++) {
        int a;
        std::cin >> a;
        --a;
        int r = a / N;
        int c = a % N;

        R[r]++;
        C[c]++;
        if (r == c) ++d0;
        if (r + c == N - 1) ++d1;
        
        if (R[r] == N || C[c] == N || d0 == N || d1 == N) {
            ans = i + 1;
            break;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}

