#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, M;
    std::cin >> N >> M;

    ll INF = 0;
    std::vector<int> L(N);
    for (int i = 0; i < N; i++) {
        std::cin >> L[i];
        INF += L[i] + 1;
    }

    auto f = [&](ll w) -> int {
        int rcnt = 1;
        ll c = 0; // used buffer

        for (int i = 0; i < N; i++) { // O(N)
            if (c == 0) {
                c = L[i];
            }
            else if (c + 1 + L[i] <= w) {
                c += 1 + L[i];
            }
            else { // new line
                rcnt++;
                c = L[i]; // start 
            }
        }
        return rcnt;
    };

    auto binarySearch = [&]() -> ll {
        ll l = *std::max_element(L.begin(), L.end()) -1;
        ll r = INF;

        while (r - l > 1) {
            ll mid = l + (r - l) / 2;
            if (f(mid) <= M) r = mid;
            else l = mid;
        }
        return r;
    };
    ll ans = binarySearch();

    std::cout << ans << std::endl;
    return 0;
}
