#include <bits/stdc++.h>

using ll = long long;
static const ll MOD = 998244353;

int mod(ll a, ll b) {return (a % b + b) % b;}

int main() {
    int Q;
    std::cin >> Q;

    std::vector<ll> p(Q + 1); // power of 10
    p[0] = 1;
    for (int i = 1; i <= Q; i++) {
        p[i] = mod(p[i - 1] * 10, MOD);
    }
    
    ll ans = 1;

    std::queue<int> q;
    q.push(1);

    while (Q--) {
        int type;
        std::cin >> type;

        if (type == 1) { // append x
            int x;
            std::cin >> x;
            q.push(x);

            ans = mod(ans * 10 + x, MOD);
        }
        else if (type == 2) {
            int x = q.front(); q.pop();

            ans = mod(ans - x * p[q.size()], MOD);
        }
        else std::cout << ans << "\n";
    }


    return 0;
}

