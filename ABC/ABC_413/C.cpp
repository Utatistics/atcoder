#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<int, int>;

int main() {
    int Q;
    std::cin >> Q;

    std::deque<P> dq;
    while (Q--) {
        // input
        int t;
        std::cin >> t;

        // solve
        std::vector<P> ans;
        if (t==1) {
            int c, x;
            std::cin >> c >> x;
            dq.push_back({c, x});
        }
 
        if (t==2) {
            int k;
            std::cin >> k;
            
            ll ans = 0;
            while (k) {
                auto p = dq.front(); dq.pop_front();
                if (p.first > k) {
                    dq.push_front({p.first - k, p.second});
                    ans += 1LL * k * p.second;
                }
                else // k > p.first 
                    ans += 1LL * p.first * p.second;

                k = std::max(0, k - p.first);
            }
            // presentation
            std::cout << ans << "\n";
        }
    }
 
    return 0;
}
