#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input processing
    int N, K;
    std::cin >> N >> K;
    ll X;
    std::cin >> X;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];


    // solve
    std::sort(A.begin(), A.end(), [](int a, int b){ return a > b; });
    
    int ans = 0;
    ll M = 0;
    bool status = false;
    for (int i = 0; i < N; i++) {
        ans++;
        if (i <= N - K - 1)
            continue;        
        M += A[i];
        if (M >= X) {
            status = true;
            break;
        }
    }
    if (!status) ans = -1;

    // presentation
    std::cout << ans << std::endl;

    return 0;
}

