#include <bits/stdc++.h>

using ll = long long;

int main() {
    ll N;
    std::cin >> N;

    N--; // 1 to 0 index
    if (N == 0) { // edge case
        std::cout << 0 << std::endl;
        return 0;
    }

    std::string ans = "";
    while (N) {
        ans += '0' + (N % 5 * 2); // '0' does std::to_string()
        N /= 5;
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << ans << std::endl;

    return 0;
}

