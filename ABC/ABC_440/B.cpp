#include <bits/stdc++.h>

int main() {
    // input processing
    int N;
    std::cin >> N;
    
    std::vector<std::pair<int, int>> T(N);
    for (int i = 0; i < N; i++) {
        int t;
        std::cin >> t;
        T[i] = {t, i + 1};
    } 

    // solve
    // O(N * logN), descending (remove 3rd arg if ascending), #include <algorithm> needed
    std::sort(T.begin(), T.end());

    for (int i = 0; i < 3; i++) std::cout << T[i].second << " ";
    std::cout << "\n";

    return 0;
}

