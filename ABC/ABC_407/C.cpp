#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    int N = S.size();
    int ans = 0;

    int rc = 0;  // total rotations mod 10
    for (int i = N - 1; i >= 0; i--) {
        int b = ((S[i] - '0' - rc) + 10) % 10; // apply 
        ans += 1 + b; // one A + b times B
        rc = (rc + b) % 10;
    }

    std::cout << ans << std::endl;
    return 0;
}
