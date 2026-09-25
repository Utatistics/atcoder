#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::string S;
    std::cin >> S;

    std::vector<int> C(N);
    for (int i = 0; i < N; i++) {
        std::cin >> C[i];
        --C[i];
    }

    std::vector<std::deque<char>> vdq(M);
    for (int i = 0; i < N; i++) {
        vdq[C[i]].push_back(S[i]);
    }
    for (int i = 0; i < M; i++) {
        char c = vdq[i].back(); vdq[i].pop_back();
        vdq[i].push_front(c);
    }

    
    for (int i = 0; i < N; i++) {
        std::cout << vdq[C[i]].front();
        vdq[C[i]].pop_front();
    }
    std::cout << std::endl;

    return 0;
}

