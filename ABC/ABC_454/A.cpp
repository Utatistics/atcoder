#include <bits/stdc++.h>

int main() {
    int L, R;
    std::cin >> L >> R;

    int ans = 0;
    for (int i = L; i <= R; i++) {
        ans++;
    }

    std::cout << ans << std::endl;
    return 0;
}
