#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) std::cin >> S[i];
    
    int ans = N;
    for (int i = 0; i < (1 << N); i++) { // subset 0 to 2^N - 1 
        std::vector<int> cnt(M, 0);
        int c = 0;
        for (int j = 0; j < N; j++) { 
            if (i & (1 << j)) { 
                for (int k = 0; k < M; k++) 
                    cnt[k] += (S[j][k] == 'o') ? 1 : 0;
                ++c;
            }
        }
        bool flg = true;
        for (int k = 0; k < M; k++) {
            if (cnt[k] == 0) {
                flg = false;
                break;
            }
        }
        if (flg) ans = std::min(ans, c);
    }

    std::cout << ans << std::endl; 
    return 0;
}

