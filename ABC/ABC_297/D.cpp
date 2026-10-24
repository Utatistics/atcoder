#include <bits/stdc++.h>

using ll = long long;

int main() {
    ll A, B;
    std::cin >> A >> B;

    ll ans = 0;
    while (A != B) { // O(log N) apparently...
        if (A < B) {
            ans += (B / A);
            if (B % A == 0) {
                --ans;
                break;
            }
            B = B % A;
        }
        else {
            ans += (A / B);
            if (A % B == 0) {
                --ans;
                break;
            }
            A = A % B;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}

