#include <bits/stdc++.h>

int main() {
    int N;
    std::string S;

    std::cin >> N >> S;

    int ans = 0;

    char prev = S[0];
    int cnt = prev == 'R' ? 1 : 0;

    for (int i = 1; i < N; i++) {
        if (S[i] == 'R') {
            if (S[i - 1] == 'R') ++cnt;
            else cnt = 1;
        }
        
        if (S[i] == 'S') {
            ans = std::max(ans, cnt);
            cnt = 0;
        }
    }
    ans = std::max(ans, cnt);
    
    std::cout << ans << std::endl;
    return 0;
}

