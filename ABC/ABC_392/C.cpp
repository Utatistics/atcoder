#include <bits/stdc++.h>

int main() {
    // input
    int N;
    std::cin >> N;

    std::unordered_map<int, int> mpp; // O(1)
    for (int i = 0; i < N; i++) { // point to
        int p;
        std::cin >> p;
        p--;
        mpp[i] = p;
    }
    
    std::unordered_map<int, int> mpb; // O(1)
    std::map<int, int> mbp; // O(log N)
    for (int i = 0; i < N; i++) { // number
        int q;
        std::cin >> q;
        q--;
        mpb[i] = q;
        mbp[q] = i;
    }

    // presentation
    for (auto [b, p] : mbp) { // O( N * log N )
        std::cout << mpb[mpp[p]] + 1 << " ";
    }
    std::cout << std::endl;

    return 0;
}

