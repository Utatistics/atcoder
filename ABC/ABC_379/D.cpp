#include <bits/stdc++.h>

using ll = long long;

int main() {
    int Q;
    std::cin >> Q;

    std::deque<ll> dq;

    ll offset = 0;
    while (Q--) {
        int t;
        std::cin >> t;
     
        if (t == 1) {
            dq.push_front(offset); // store offset at birth
        }
        else if (t == 2) {
            int T;
            std::cin >> T;
            offset += T;
            
        } 
        else {
            int H;
            std::cin >> H;

            int ans = 0;
            while (!dq.empty()) {
                ll x = dq.back();
                if (offset - x >= H) {
                    dq.pop_back();
                    ++ans;
                }
                else break;
            }
            std::cout << ans << "\n";
        }

    }

    return 0;
}

