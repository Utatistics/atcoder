#include <bits/stdc++.h>

using ll = long long;

char flip(char c) {
    if (std::islower(c)) return c - 'a' + 'A';
    else return c - 'A' + 'a';
}

int f(ll l, ll r, ll i) {
    if (r - l == 1) return 0;

    ll m = (l + r) / 2;

    if (i < m)
        return f(l, m, i);
    else
        return f(m, r, i) + 1;
}

int main() {
    std::string S;
    std::cin >> S;

    int N = S.size();

    int Q;
    std::cin >> Q;

    while (Q--) {
        ll k;
        std::cin >> k;
        --k;

        ll i = k / N;
        int j = k % N;

        char ans = S[j];
        int cnt = f(0, 1LL << 60, i);

        if (cnt % 2) ans = flip(ans);

        std::cout << ans << " ";
    }

    std::cout << std::endl;

    return 0;
}


//                       [0,8)
//                    /        \
//              left /          \ right (+1 flip)
//                  /            \
//              [0,4)          [4,8)
//             /    \          /    \
//        left      right   left    right
//         /         (+1)    /       (+1)
//      [0,2)      [2,4)    [4,6)    [6,8)
//     /   \       /   \    /   \    /   \
//    0     1     2     3  4     5  6     7
