#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(M);
    for (int i = 0; i < M; i++) std::cin >> A[i];
    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) std::cin >> S[i];
    
    int t = 0; // max score
    std::vector<int> s(N, 0); // scores
    std::vector<std::vector<int>> p(N); // remaining problems
    for (int i = 0; i < N; i++) {        
        s[i] += i + 1; // bonus

        for (int j = 0; j < M; j++) {
            if (S[i][j] == 'o') s[i] += A[j];
            else p[i].push_back(A[j]);
        }
        t = std::max(t, s[i]);
        std::sort(p[i].rbegin(), p[i].rend());
    }

    auto f = [&](int i) -> int {
        if (s[i] == t) return 0;

        int ans = 0;
        for (auto x : p[i]) {
            ++ans;
            s[i] += x;
            if (s[i] >= t) break;
        }
        return ans;
    };

    for (int i = 0; i < N; i++) {
        std::cout << f(i) << "\n";
    }

    return 0;
}

