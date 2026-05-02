#include <bits/stdc++.h>

static const int MOD = 998244353;

using ll = long long;

int main() {
    std::string b = "z";
    std::string S;
    std::cin >> S;
    S = b + S;
    int N = S.size();

    ll  ans = 0;
    ll s = 0;
    
    int r = 0; // right ptr
    for (int l = 0; l < N;) { // left ptr
        while (r + 1 < N) { // monotonically increasing
            if (S[r] != S[r + 1]) r++;
            else break;
        }

        if (l == r && r + 1 < N) { // l caught up 
            s = 0; // reset
            ++r;
        }
        else { // l catches up
            int n = r - l;
            ll x = 1LL * n * (n + 1) / 2;
            if (s < x) {
                ans = (ans + x) % MOD;
                s = x;
            }
            l++;
        }
    }
    
    std::cout << ans << std::endl;
    return 0;
}
