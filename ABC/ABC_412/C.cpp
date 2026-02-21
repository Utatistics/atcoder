#include <bits/stdc++.h>

using ll = long long;

int binary_search(ll key, const std::vector<int> &A) {
    int left = -1;
    int right = (int)A.size();
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (A[mid] <= key) left = mid;
        else right = mid;
    }
    return left; //-1 if no domino falls
}

int main () {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        int M = N - 2;
        int s, e;
        std::vector<int> S(M);
        std::cin >> s;
        for (int i = 0; i < M; i++) std::cin >> S[i];
        std::cin >> e;

        std::sort(S.begin(), S.end());

        int ans = 2;
        ll k = s;

        while (2LL * k < e) {
            int i = binary_search(2LL * k, S);
            if (i < 0) break;
            if (S[i] == k) break; // no progress

            k = S[i];
            ans++;
        }

        if (M == 0) {
            if (2LL * s < e) std::cout << -1 << "\n";
            else std::cout << ans << "\n";
        }
        else if (2LL * k < e) {
            std::cout << -1 << "\n";
        }
        else {
            std::cout << ans << "\n";
        }
    }

    return 0;
}
