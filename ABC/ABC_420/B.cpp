#include <bits/stdc++.h>

int main() {
    // input processing
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> V(N); // vote, N * M
    for (int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;
        for (char c : s) V[i].push_back(c - '0'); // size M
    }

    // solve
    std::vector<int> W(M); //  winner
    for (int j = 0; j < M; j++) {
        int c0 = 0;
        int c1 = 0;
        for (int i = 0; i < N; i++) {
            if (V[i][j] == 0) c0++;
            else c1++;
        }
        if (c0 == 0) W[j] = 1;
        if (c1 == 0) W[j] = 0;
        else W[j] = (c0 < c1) ? 0 : 1;
    } 

    int ms = 0; //  max score
    std::vector<int> S(N, 0); // score
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (V[i][j] == W[j]) S[i]++;
        }
        ms = std::max(ms, S[i]);
    }

    // presentation
    for (int i = 0; i < N; i++) 
        if (S[i] == ms) std::cout << i + 1 << " "; // 0 to 1th origin
    std::cout << std::endl;

    return 0;
}

