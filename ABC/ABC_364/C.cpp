#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;    
    std::cin >> N;
    ll X, Y;
    std::cin >> X >> Y;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < N; i++) std::cin >> B[i];

    std::sort(A.begin(), A.end(), [](int a, int b){ return a > b; }); // O(N * logN)
    std::sort(B.begin(), B.end(), [](int a, int b){ return a > b; }); // O(N * logN)
    
    std::vector<ll> psa(N + 1, 0);
    for (int i = 1; i <= N; i++) psa[i] = psa[i - 1] + A[i - 1];
    std::vector<ll> psb(N + 1, 0);
    for (int i = 1; i <= N; i++) psb[i] = psb[i - 1] + B[i - 1];

    auto f = [&](ll k, const std::vector<ll>& A) -> int {
        int left = 0;
        int right = A.size();
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (A[mid] > k) right = mid;
            else left = mid;
        }
        return right;
    };

    int a = std::min(f(X, psa), N);
    int b = std::min(f(Y, psb), N);
    std::cout << std::min(a, b) << std::endl;

    return 0;
}

