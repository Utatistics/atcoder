#include <bits/stdc++.h>

using ll = long long;
using T = std::tuple<int, int, int>;

static const int MAX = 1e9;

int main() {
    // input
    int D, G;
    std::cin >> D >> G;

    std::vector<int> P;
    std::vector<T> B; // bonus

    for (int i = 0; i < D; i++) {
        int p;
        std::cin >> p;
        int l = P.size();
        for (int j = 0; j < p; j++) P.push_back(100 * (i + 1));
        int r = P.size();

        int b;
        std::cin >> b;
        B.push_back({b, l, r});
    }

    // solve
    int ans = MAX;
    int N = P.size();
    for (int i = 0; i < (1 << N); i++) { // subset 0 to 2^N - 1
        ll s = 0;
        int cnt = 0;
        std::vector<bool> status(N, false); // bonus
        for (int j = 0; j < N; j++) { // checking jth bit of given i
            if (i & (1 << j)) { // apply mask (1 << j) to i (bit seq) to see if jth bit of i is active
                status[j] = true;
                s += P[j];
                cnt++;
            }
        }

        for (auto [b, l, r] : B) { // bonus round
            bool bonus = true;
            for (int k = l; k < r; k++) {
                if (status[k] == false) {
                    bonus = false;
                    break;
                }
            }
            if (bonus) s += b;
        }

        if (s >= G) ans = std::min(ans, cnt);
    }

    // presentation
    std::cout << ans << std::endl;

    return 0;
}
