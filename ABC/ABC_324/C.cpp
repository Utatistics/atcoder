#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::string T;
    std::cin >> T;
    int M = (int)T.size();

    std::vector<std::string> S(N);
    std::vector<int> cnt(N, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
        cnt[i] = (int)S[i].size();
    }

    auto f = [&](int k) -> bool {
        int n = (int)S[k].size();
        if (std::abs(M - n) > 1) {
            return false;
        }

        int i = 0, j = 0;
        int diff = 0;
        while (i < M && j < n) {
            if (T[i] == S[k][j]) {
                ++i; ++j;
            } 
            else {
                ++diff;
                if (diff > 1) return false;
                if (M > n) ++i; // T has an extra character
                else if (M < n) ++j;  // S has an extra character
                else {
                    ++i;++j; // replacement
                }
            }
        }
        return true;
    };

    std::vector<int> K;
    for (int i = 0; i < N; i++) if(f(i)) K.push_back(i + 1);
    std::cout << (int)K.size() << std::endl;
    for (auto i : K) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

