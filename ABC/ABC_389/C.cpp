#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<ll, ll>;

int main() {
    int Q;
    std::cin >> Q;

    std::deque<P> dq;
    
    ll c = 0;
    while (Q--) {
        int t;
        std::cin >> t;

        if (t == 1) {
            int l;
            std::cin >> l;
            if (dq.empty()) dq.push_back({0, l}); // init
            else {
                P p = dq.back();
                dq.push_back({p.second, p.second + l});
            }
        }

        if (t == 2) {
            P p = dq.front();
            c += p.second - p.first; // increment by l
            dq.pop_front();
        }

        if (t == 3) {
            int k;
            std::cin >> k;
            std::cout << dq[k - 1].first - c << "\n";
        }
        
    }
    return 0;
}

