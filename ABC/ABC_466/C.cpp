#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int ans = 0;
    int r = 1;
    for (int l = 1; l <= N; ++l) {
        if (r < l) r = l;
        while (r + 1 <= N) {
            std::cout << "? " << l << " " << r + 1 << std::endl;
            std::string res;
            std::cin >> res;

            if (res == "Yes") ++r;
            else break;
        }
        ans += r - l;
    }

    std::cout << "! " << ans << std::endl;
    return 0;
}
