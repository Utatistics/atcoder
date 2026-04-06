#include <bits/stdc++.h>

int main() {
    std::string L, R;
    std::cin >> L >> R;

    int dl = L.size();
    int dr = R.size();
    int il = std::stoi(L[0]);
    int ir = std::stoi(R[0]);

    int ans = 0;
    for (int d = 2; d <= 18; d++) {
        for (int i = 1; i <= 9; i++) {
            if (d < dl || d > dr) continue;
            else if (d == dl || d == dr) {

            }
            else ans += i * (d - 1);
        }
    }

    if (R == "1000000000000000000") ans++; // 1e18, d=19
    std::cout << ans << std::endl;

    return 0;
}

