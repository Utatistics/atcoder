#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    // input
    int N, Q;
    std::cin >> N >> Q;
    
    // solve
    std::vector<P> A(N); // {value : index}
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        A[i] = {a, i};
    }
    std::sort(A.begin(), A.end()); // O(N * logN)i
   
    std::map<int, int> m; // {i : i'} for before/after sort
    int j = 0;
    for (auto [a, i] : A) {
        m[i] = j;
        j++;
    } 
    
    while (Q--) {
        int K;
        std::cin >> K;
        
        std::multiset<int> B; // up to 5
        for (int k = 0; k < K; k++) { // up to 5 iter
            int b;
            std::cin >> b;
            b--; // 0 index
            B.insert(m[b]);
        }

        // presentation
        int argmin = 0; // argmin for sorted A
        int smin = *B.begin(); // minimum index
        
        if (smin == 0) {
            int cnt = 0;
            for (const int b : B) {
                if (b != smin && b != smin + cnt) break;
                argmin = smin + cnt;
                cnt++;
            };

            argmin = argmin + 1; // next aviailabe
        }
        else argmin = 0;

        std::cout << A[argmin].first << "\n";
    }
    return 0;
}
