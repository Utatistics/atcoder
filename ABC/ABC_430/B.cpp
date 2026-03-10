#include <bits/stdc++.h>

int N, M;
std::vector<char> A;

void slide(int i, int j, std::vector<char> &g) {
    for (int ii = i; ii < i + M; ii++) {
        for (int jj = j; jj < j + M; jj++) {
            int kk = jj + ii * N;
            g.push_back(A[kk]);
        }
    }
}

int main() {
    // input 
    std::cin >> N >> M;
    A.resize(N * N);
    for (int i = 0; i < N; i++) { // H for rownum
        for (int j = 0; j < N; j++) { // W for colnum
            std::cin >> A[j + i * N];
        }
    }
    
    // solve
    int cnt = 0;
    int dup = 0; // dup counter
    std::set<std::vector<char>> S;
    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            std::vector<char> g; // grid

            slide(i, j, g);
            if (S.find(g) != S.end()) dup++; // O(log N)
            else S.insert(g);
            cnt++;
        }
    }

    std::cout << cnt - dup << std::endl;

    return 0;
}



