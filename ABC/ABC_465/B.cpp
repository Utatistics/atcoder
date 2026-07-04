#include <bits/stdc++.h>

int main() {
    int X, Y, L, R, A, B;
    std::cin >> X >> Y >> L >> R >> A >> B;

    int ans = 0;
    for (int i = A; i < B; i++) {
        if (i < L || R <= i) { 
            ans += Y;
        }
        else {
            ans += X;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
