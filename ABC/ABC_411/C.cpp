#include <bits/stdc++.h>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    int ans = 0;
    std::vector<int> A(N, 0);

    while (Q--) {
        int i;
        std::cin >> i;
        i--;

        int l = (i == 0) ? 0 : A[i - 1];
        int r = (i == N - 1) ? 0 : A[i + 1];

        if (A[i] == 0) { // white -> black
            if (l == 0 && r == 0) ans++;
            if (l == 1 && r == 1) ans--;
        } else { // black -> white
            if (l == 0 && r == 0) ans--;
            if (l == 1 && r == 1) ans++;
        }

        A[i] ^= 1;  // flip

        std::cout << ans << std::endl;
    }
}
