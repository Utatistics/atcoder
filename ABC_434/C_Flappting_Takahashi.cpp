#include<iostream>
#include<vector>
#include<algorithm>

int main () {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int N, H;
        std::cin >> N >> H;
        std::vector<int> t(N, 0);

        int t0 = 0;
        int h0 = H; // current height
        bool ans = true;
        for (int j = 0; j < N; j++) {
            int t1, l, u;
            std::cin>> v >> l >> u;

            int td = t1 - t0;
            if (h0 >= l) int h1 = std::abs(h0, l);
            else if  (h0 <= u) int h1 =std::abs(h0, u);
            int hd = h1 - h0;

            if (td < hd) {
                t0 = t1; // next iter
                h0 = h1;
            }
            else ans = false;
        }

        if (ans) std::cout << "Yes" << "\n";
        else std::cout << "No" << "\n";
            
    }

    return 0;
}
