#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input processing
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    // solve
    int r = 0;
    ll s = 0;
    for (int l = 0; l < N; l++) {
        while (r < N && /* condition */) {
            // e.g. s += A[r];
            r++;
        }

        // ans update here

        if (r == l) ++r;
        // e.g. else s -= A[l];
    }

    return 0;
}

