#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    int M = 0;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        M = std::max(M, A[i]);
    }

    // solve
    std::vector<int> imos(M + 1, 0); // 1 dim imos
    for (int i = 0; i < N; i++) { // O(N)        
        imos[0]++;
        imos[A[i]]--;
    }

    std::vector<int> B(M, 0);
    for (int i = 0; i < M; i++) // O(N)
        B[i] = (i == 0) ? imos[i] : B[i - 1] + imos[i];

    int i = 0;
    while (i < (int)B.size()) {
        if (B[i] < 10) {
            i++;
            continue;
        }
        if (i + 1 == (int)B.size())
            B.push_back(0);   // grow dynamically
        B[i] %= 10;
        B[i + 1] += B[i] / 10;

        i++;
    }

    // presentation
    std::string ans = "";
    for (int i = B.size() - 1; i >= 0 ; i--) 
         ans += std::to_string(B[i]);

    std::cout << ans << std::endl;

    return 0;
}

