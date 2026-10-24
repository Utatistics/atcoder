#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int l = 1, r = N; // S[l] = 0, S[r] = 1 always
    while (r - l > 1) {
        int i = l + (r - l) / 2;

        std::cout << "? " << i << std::endl;
        int s;
        std::cin >> s;

        if (s == 1) r = i;
        else l = i;
    }

    std::cout << "! " << l << std::endl;
    return 0;
}

