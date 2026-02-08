#include <iostream>
#include <cmath>

static const double PI=3.141592653589793; //NASA 15th

int main () {
    int T, L, X, Y, Q;
    std::cin >> T >> L >> X >> Y >> Q;

    for (int i = 0; i < Q; i++) {
        // polor coordinates
        double r = L / 2.0;
        int e;
        std::cin >> e;
        double theta = e % T * 2.0 * PI; // vertical
        double phi; // horizontal

        // cartesian coordinates
        // int x = 0;
        // int y = r * std::sin(theta) * std::sin(phi);
        // int z = r * std::cos(theta) + r;
        
        int x = 0;
        int y = -r * std::sin(theta);
        int z = r - r * std::cos(theta);

        // depression angle
        double d0 = std::sqrt((x-X) * (x-X) + (y - Y) * (y - Y));
        double d1 = z;
        ans = atan2(d1, d0);
        
        std::cout << ans;
    }
}
