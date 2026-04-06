#include <bits/stdc++.h>

int main() {
    // input
    int K;
    std::cin >> K;

    std::string S, T;
    std::cin >> S >> T;

    int N = S.size();
    int M = T.size();

    // solve
    int i = 0;
    int j = 0;
    if (N - M == K) {
        for (j = 0; j < M; j++) {
            while (S[i] != T[j]) {
                i++;
            }
            if (i - j > K) break;
            i++;
        }
        if (i - j > 1) std::cout << "No\n";
        else std::cout << "Yes\n";
    }

    else if (M - N == K) {
        for (i = 0; i < N; i++) {
            while (S[i] != T[j]) {
                j++;
            }
            if (j - i > K) break;
            j++;
        }
        if (j - i > K) std::cout << "No\n";
        else std::cout << "Yes\n";
    }

    else if (N == M){
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] != T[i]) cnt++;
        }
        if (cnt > K) std::cout << "No\n";
        else std::cout << "Yes\n";
    }

    else std::cout << "No\n";

    return 0;
}

