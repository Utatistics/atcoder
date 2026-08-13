#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N ,T;
    std::cin >> N >> T;

    std::vector<ll> A(N, 0); // score
    std::map<ll, int> cnt; // unique score
    
    int ans = 1; // 0 counts
    cnt[0] = N;

    for (int i = 0; i < T; i++) {
        int a, b;
        std::cin >> a >> b;
        --a; // 0 index

        if (cnt[A[a]] == 1) --ans;
        cnt[A[a]]--;
        
        A[a] += b;

        if (cnt[A[a]] == 0) ++ans;
        cnt[A[a]]++;

        std::cout << ans << std::endl;
    }

    return 0;
}

