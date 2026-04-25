#include <bits/stdc++.h>

struct C { int above; int below; }; // card 

int main() {
    // input processing
    int N, Q;
    std::cin >> N >> Q;

    std::vector<C> L(N); // linked list
    for (int i = 0; i < N; i++) L[i] = {-1, -1};
    
    // solve
    while (Q--) {
        int c, p;
        std::cin >> c >> p;
        c--; p--; // 1 to 0 origin

        if (L[c].below != -1) L[L[c].below].above = -1;
        L[c].below = p;
        L[p].above = c;
    }

    // presentation
    for (auto x : L) {
        if (x.below != -1) { // no card in the pile
            std::cout << 0 << " ";
            continue;
        }

        int ans = 1;
        while (x.above >= 0) {
            ans++;
            x = L[x.above];
        }
        std::cout << ans << " ";
    }
    std::cout << "\n";

    return 0;
}

