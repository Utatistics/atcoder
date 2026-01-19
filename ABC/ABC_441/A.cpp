#include <bits/stdc++.h>

int main() {
    // input processing
    int P, Q, X, Y;
    std::cin >> P >> Q >> X >> Y;

    // solve
    std::string ans = "Yes";
    if (!(P <= X && X <= P + 99))
        ans = "No";
    if (!(Q <= Y && Y <= Q + 99))
        ans = "No";

    // presentation
    std::cout << ans << std::endl;

    return 0;
}

