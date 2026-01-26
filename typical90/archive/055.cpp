#include <bits/stdc++.h>

using ll = long long;

int main () {
    // input processing
    int N, P, Q;
    std::cin >> N >> P >> Q;
    
    int K = 5;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    
    // solve
    int cnt = 0;
    int ans = 0;
    std::vector<int> mask(N,0); // 0 or 1
    std::fill(mask.begin(), mask.begin() + K, 1); // init first Ks with 1

    do {
        ll p = 1;
        for (int i = 0; i < N; i++) p = (mask[i] == 1) ? (p * A[i]) % P: p;
        if (p == Q) ans++;
        ++cnt;

    } while (std::prev_permutation(mask.begin(), mask.end()));

    // presentation
    std::cout << cnt << std::endl;
    std::cout << ans << std::endl;

    return 0;
}
