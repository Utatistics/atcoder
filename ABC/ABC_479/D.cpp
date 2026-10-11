#include <bits/stdc++.h>

using ll = long long;

static const ll INF = 1e18;

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<ll> L(N), R(N);
    for (int i = 1; i < N; i++) std::cin >> L[i];
    for (int i = 0; i < N - 1; i++) std::cin >> R[i];

    std::vector<int> LR(N, -1);
    ll rmin = INF;
    for (int i = 1; i < N; i++) {
        if (R[i - 1] < rmin) {
            LR[i] = i - 1;
            rmin = R[i - 1];
        }
        else {
            LR[i] = LR[i - 1];
        }
    }
    std::vector<int> RL(N, -1);
    ll lmin = INF;
    for (int i = N - 2; i >= 0; i--) {
        if (L[i + 1] < lmin) {
            RL[i] = i + 1;
            lmin = L[i + 1];
        }
        else {
            RL[i] = RL[i + 1];
        }
    }

    while (Q--) {
        int s, t;
        std::cin >> s >> t;
        --s; --t;

        ll c0 = 0, c1 = INF;
        if (s < t) {
            c0 = R[s];
            if (s > 0) c1 = L[s] + R[LR[s]];
        }
        else {
            c0 = L[s];
            if (s < N - 1) c1 = R[s] + L[RL[s]];
        }

        std::cout << std::min(c0, c1) << "\n";
    }

    return 0;
}
