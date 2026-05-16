#include <bits/stdc++.h>

using ll = long long;

using P = std::pair<int, int>;
static const int MAX = 1e9 + 7; // max dist

int main() {
    int N;
    std::cin >> N;
 
    ll ans = 0;
    std::set<P> s;
    { // init
        int x;
        N--;
        std::cin >> x;
        s.insert({0, x}); // {val, dist}
        s.insert({x, x});
        ans = 1LL * 2 * x;
        std::cout << ans << "\n";
    }
    
    while (N--) {
        int x;
        std::cin >> x;

        auto it = s.lower_bound({x, -1});
        auto p = *(std::prev(it));
        
        if (it == s.end()) { // one-sided
            int d = x - p.first; // new dist
            ans += d;
            if (p.second > d) {
                ans -= p.second;
                ans += d;
                p.second = d;
            }

            s.erase(std::prev(it));
            s.insert(p);
            s.insert({x, d});
        }
        else { // two-sided
            auto q = *it; // safe   
            
            int d0 = x - p.first;
            int d1 = q.first - x;
            int d = std::min(d0, d1);
            ans += d;
            ans -= p.second;
            ans -= q.second;

            int pd = std::min(p.second, d0);
            int qd = std::min(q.second, d1);
            ans += pd;
            ans += qd;

            p.second = pd;
            q.second = qd;
            
            s.erase(std::prev(it));
            s.erase(it);
            s.insert(p);
            s.insert(q);
            s.insert({x, d});
        }
         
        std::cout << ans << "\n";
    }

    return 0;
}
