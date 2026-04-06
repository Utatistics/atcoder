#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < N; i++) std::cin >> B[i];

    bool a = true;  // A[N-1] is reachable
    bool b = true;  // B[N-1] is reachable

    for (int i = N - 1; i > 0; i--) {
        bool new_a = false;
        bool new_b = false;

        // if X[i] = A[i]
        if (a) {
            if (std::abs(A[i] - A[i-1]) <= K) new_a = true;
            if (std::abs(A[i] - B[i-1]) <= K) new_b = true;
        }

        // if X[i] = B[i]
        if (b) {
            if (std::abs(B[i] - A[i-1]) <= K) new_a = true;
            if (std::abs(B[i] - B[i-1]) <= K) new_b = true;
        }

        a = new_a;
        b = new_b;
    }

    std::cout << (a || b ? "Yes\n" : "No\n");
}
