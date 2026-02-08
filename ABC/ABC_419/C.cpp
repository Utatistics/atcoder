#include <bits/stdc++.h>

int main() {
    // input processing
    int N;
    std::cin >> N;

    int rmin = 1e9;
    int rmax = 1;
    int cmin = 1e9;
    int cmax = 1;

    for (int i = 0; i < N; i++) {
        int r, c;
        std::cin >> r >> c;

        rmin = std::min(rmin, r);
        rmax = std::max(rmax, r);
        cmin = std::min(cmin, c);
        cmax = std::max(cmax, c);
    }

    // solve
    int rd = rmax - rmin;
    int cd = cmax - cmin;
    std::cout << (std::max(rd, cd) + 1) / 2 << std::endl;
    
    return 0;
}

