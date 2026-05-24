#include <bits/stdc++.h>

using ll = long long;

static const ll MOD = 1000000007LL;

struct fenwickTree {
    int n;
    std::vector<ll> t; // internal array

    fenwickTree(int n) : n(n), t(n + 1, 0) {} // 0th index unused

    void update(int i, ll x) { // add x to index i
        while (i <= n) {
            t[i] += x;
            i += i & -i;
        }
    }
    ll query(int i) { // sum from 1 to i
        ll res = 0;
        while (i > 0) {
            res += t[i];
            i -= i & -i;
        }
        return res;
    }
    ll range(int l, int r) { // sum from l to r
        return query(r) - query(l - 1);
    }
};


int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) std::cin >> A[i];

    std::vector<ll> fact(N + 1, 1); // 0! = 1
    for (int i = 1; i <= N; ++i) // pre-compute factorials modulo MOD
        fact[i] = (fact[i - 1] * i) % MOD;

    fenwickTree fw(N);
    for (int i = 1; i <= N; ++i) { // initially all numbers 1..N are unused (i.e. 1)
        fw.update(i, 1);
    }

    ll ans = 1; // lexicographical order is 1-indexed
    for (int i = 0; i < N; ++i) {
        int ci = fw.query(A[i] - 1); // count unused numbers smaller than a[i]
        ans = (ans + (ll)ci * fact[N - 1 - i]) % MOD;
        fw.update(A[i], -1); // mark a[i] as used (i.e. 0)
    }

    std::cout << ans << std::endl;

    return 0;
}
