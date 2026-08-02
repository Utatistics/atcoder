#include <bits/stdc++.h>

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] != 'x') continue;
        
        bool l = true, r = true;
        if (i > 0) 
            l = S[i - 1] != 'o';
        if (i < N - 1)
            r = S[i + 1] != 'o';
        
        ans += l && r ? 1 : 0;
        
    }
    std::cout << ans << std::endl;
    return 0;
}

