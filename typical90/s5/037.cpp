#include <bits/stdc++.h>

using ll = long long;
static const ll INF = 1LL << 60;

template<typename T>
class Monoid {
public:
    T unit;
    Monoid() { unit = -INF; }
    T calc(T a, T b) { return std::max(a, b); } // query max
};

template<typename T>
class SegTree {
public:
    int n;
    std::vector<T> tree;
    Monoid<T> mono;

    SegTree(std::vector<T> &v) {
        n = 1 << (int)std::ceil(std::log2(v.size()));
        tree = std::vector<T>(n << 1);

        for(int i = 0; i < (int)v.size(); i++)
            update(i, v[i]);
        for(int i = v.size(); i < n; i++)
            update(i, mono.unit);
    }

    void update(int k, T x) {
        k += n;
        tree[k] = x;
        for(k >>= 1; k > 0; k >>= 1){
            tree[k] = mono.calc(tree[k << 1], tree[k << 1 | 1]);
        }
    }

    T query(int l, int r) { // return max
        T res = mono.unit;
        l += n;
        r += n;

        while(l < r) {
            if(l & 1) res = mono.calc(res, tree[l++]);
            if(r & 1) res = mono.calc(res, tree[--r]);
            l >>= 1; r >>= 1;
        }
        return res;
    }

    T operator[](int k) {
        return tree[tree.size() - n + k];
    }
};

int main() {
    int W, N;
    std::cin >> W >> N;

    std::vector<ll> dp(W + 1, -INF); // dp[i]:= max value after considering ith, -INF if impossible
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        int L, R;
        ll V;
        std::cin >> L >> R >> V;

        SegTree<ll> st(dp);

        std::vector<ll> next = dp;
        for (int j = L; j <= W; j++) {
            int l = std::max(0, j - R);
            int r = j - L + 1;

            ll vmax = st.query(l, r);

            if (vmax != -INF) { // valied step exits in [l, r]?
                next[j] = std::max(next[j], vmax + V);
            }
        }
        dp = std::move(next);
    }

    if (dp[W] == -INF) std::cout << -1 << '\n';
    else std::cout << dp[W] << '\n';

    return 0;
}
