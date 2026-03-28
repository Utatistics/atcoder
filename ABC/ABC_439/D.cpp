#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    ll ans = 0;

    for (int t = 0; t < 2; t++) { // max(i,j,k)=j -> min(i,j,k)=j
        std::map<int, int> m;
        for (int a : A) {
            m[a] ++;
            if (a % 5 == 0) {
                int x = a / 5;
                ans += 1LL * m[x * 3] * m[x * 7];
            }
        }
        std::reverse(A.begin(), A.end());
    }

    std::cout << ans << std::endl;

    return 0;
}

