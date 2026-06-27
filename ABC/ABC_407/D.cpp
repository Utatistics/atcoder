#include <bits/stdc++.h>

using ll = long long;           

int main() {
    int H, W;
    std::cin >> H >> W;

    int N = H * W;
    std::vector<ll> A(N);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> A[i * W + j];
        }
    }

    ll ans = 0;
    auto dfs = [&](auto&& f, int p0, int covered, ll x) -> void {
        if (p0 == N) {
            ans = std::max(ans, x);
            return;
        }
        if (covered & (1 << p0)) { // true if p0 is covered
            f(f, p0 + 1, covered, x); // skip p0
            return;
        }

        f(f, p0 + 1, covered, x ^ A[p0]); // choose p0, update x
        
        int r = p0 / W;
        int c = p0 % W;

        if (c + 1 < W) {
            int p1 = p0 + 1;
            if (!(covered & (1 << p1))) {
                f( // horizontal
                    f,
                    p0 + 1,
                    covered | (1 << p0) | (1 << p1), // cover with horizontal
                    x
                );
            }
        }

        if (r + 1 < H) { // vertical
            int p1 = p0 + W;
            if (!(covered & (1 << p1))) {
                f( // vertical
                    f,
                    p0 + 1,
                    covered | (1 << p0) | (1 << p1), // cover with 
                    x
                );
            }
        }
    };

    dfs(dfs, 0, 0, 0); // * covered and x are both bitmask
    std::cout << ans << "\n";
    return 0;
}
