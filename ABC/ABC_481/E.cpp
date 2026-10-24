#include <bits/stdc++.h>

using P = std::pair<double, double>;

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        int X, Y;
        std::cin >> X >> Y;

        std::vector<P> v;
        for (int i = 0; i < N; i++) {
            double X, Y;
            std::cin >> X >> Y;
            v.emplace_back(X, Y);
        }

        double a = v[0].second / v[1].first;
        
        std::set<P> sp, sn;
        
        for (auto [x, y] : v) {
            if (y > a * x) {
                sp.emplace(x, y);
            }
            else {
                sn.emplace(x, y);
            }
        }
        int ans = std::max(sp.size(), sn.size());


        std::cout << ans << std::endl;
    }
    return 0;
}

