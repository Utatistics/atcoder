#include <bits/stdc++.h>

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;
 
   
    if (S.find('-') == std::string::npos || S.find('o') == std::string::npos) {
        std::cout << -1 << std::endl;
        return 0; 
    }
     
    int ans = 0;

    int x = 0;
    auto si = S.find('-');
    for (int i = si + 1; i < N; i++) {
        if (S[i] == '-') {
            ans = std::max(ans, x);
            x = 0;
        }
        else ++x;
    }
    ans = std::max(ans, x);
    
    std::reverse(S.begin(), S.end());
    
    int y = 0;
    auto sj = S.find('-');
    for (int j = sj + 1; j < N; j++) {
        if (S[j] == '-') {
            ans = std::max(ans, y);
            y = 0;
        }
        else ++y;
    }
    ans = std::max(ans, y);

    std::cout << ans << std::endl;
    return 0;
}

