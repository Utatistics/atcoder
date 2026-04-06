#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    // input
    int N;
    std::cin >> N;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        std::cin >> B[i];
        B[i]--; // 0 index
    }

    int M;
    std::cin >> M;

    std::vector<std::string> S(M);
    for (int i = 0; i < M; i++) {
        std::cin >> S[i];
    }

    // solve
    std::map<char, std::set<P>> m;
    for (int i = 0; i < M; i++) {
        std::string s = S[i];
        int n = s.size();
        for (int j = 0; j < n; j++) {
            m[s[j]].insert({n, j});
        }
    }

    for (int i = 0; i < M; i++) {
        std::string s = S[i];
        if ((int)s.size() != N) {
            std::cout << "No\n";
            continue;
        }
        
        bool ans = true;
        for (int j = 0; j < N; j++) {
            P x = {A[j], B[j]};
            if (m[s[j]].count(x) == 0) ans = false;
        }

        if (ans) std::cout << "Yes\n";
        else std::cout << "No\n";
    }

    return 0;
}

