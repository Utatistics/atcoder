#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> P(N);
    for (int i = 0; i < N; i++) std::cin >> P[i];
    
    // do {
        // for (int i = 0; i < N; i++) std::cout << P[i] << " ";
        // break;

    // } while (std::prev_permutation(P.begin(), P.end()));
    
    for (int i = N - 1; i > 0; --i) {
        if (P[i - 1] > P[i]) {
            int j = N - 1;
            while (P[i - 1] < P[j]) --j;
            std::swap(P[i - 1], P[j]);
            std::reverse(P.begin() + i, P.end());
            break;
        }
    }

    for (int i = 0; i < N; i++) std::cout << P[i] << " ";
    std::cout << std::endl;
    
    return 0;
}

