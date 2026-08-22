#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, M;
    ll K;
    std::cin >> N >> M >> K;

    std::vector<ll> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    std::vector<bool> B(N, false);
    
    ll k = 0;
    for (int i = 0; i < N; i++) {
        if (i >= M && B[i - M]) {
            k -= A[i - M];
        }

        if (k + A[i] <= K) {
            B[i] = true;
            k += A[i];
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
}
