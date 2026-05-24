#include <bits/stdc++.h>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N, 0);
    std::map<int, int> m; // {num of blocks : cum num of masu}

    int z = N; // numnber of zeros
    int d = 0; // number of decrements
    
    while (Q--) {
        int t;
        std::cin >> t;

        if (t == 1) {
            int x;
            std::cin >> x;
            x--;
            
            if (A[x] - d == 0) z--;
            A[x]++;
            m[A[x]]++;
            if (z == 0) {
                z = m[1 + d] - m[2 + d];
                d++;
            }
        }
        else {
            int y;
            std::cin >> y;
            std::cout << m[y + d]<< "\n";
        }
    }
    return 0;
}

