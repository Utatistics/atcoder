#include <bits/stdc++.h>

static const int MAX = 1e9;

int main() {
    // input
    int N;
    std::cin >> N;
 
    std::vector<std::vector<int>> C(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N ; j++) {
            if (i < j) {
                int c;
                std::cin >> c;
                C[i].push_back(c);            
            }
            else {
                C[i].push_back(MAX); // dummy
            }
        }
    }

    // solve
    bool ans = false;
    for (int i = 0; i < N; i++) { // start
        for (int j = i; j < N; j++) {
            for (int k = i + 1; k < j; k++) {
                if (i >= j - 1) continue;
                int c1 = C[i][j];
                int c2 = C[i][k] + C[k][j];
                if (c1 > c2) ans = true;
            }
        }
    }

    // presentation
    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

