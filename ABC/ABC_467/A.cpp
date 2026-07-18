#include <bits/stdc++.h>

int main() {
    int H, W;
    std::cin >> H >> W;

    if (W * 10000 >= H * H * 25) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

