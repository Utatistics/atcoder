#include <bits/stdc++.h>
using ll = long long;

int binary_search(int key, const std::vector<int> &A) {
    int left = -1;
    int right = A.size();
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (A[mid] >= key) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    // input processing
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    std::sort(A.begin(), A.end());

    std::vector<ll> ps(N);
    for (int i = 0; i < N; i++)
        ps[i] = (i == 0 ? A[i] : ps[i - 1] + A[i]);

    // solve
    while (Q--) {
        int b;
        std::cin >> b;

        if (b > A[N - 1]) std::cout << -1 << '\n';
        else if (b == 1) std::cout << 1 << '\n';
        else {
            ll x;
            int k = binary_search(b, A);
            if (k == 0) x = (ll)(b - 1) * N + 1;
            else x = ps[k - 1] + (ll)(b - 1) * (N - k) + 1;
            std::cout << x << '\n';
        }
    }
}

