#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N, R, C;
    std::cin >> N >> R >> C;

    std::string S;
    std::cin >> S;

    std::string ans = "";

    std::set<P> s;
    int r = 0; int c = 0;
    s.insert({r, c}); // init
    
    for (int i = 0; i < N; i++) {
        if (S[i] == 'N') r++;
        if (S[i] == 'W') c++;
        if (S[i] == 'S') r--;
        if (S[i] == 'E') c--;
        s.insert({r, c});

        ans += (s.count({r + R, c + C}) > 0) ? '1' : '0';
    }

    std::cout << ans << std::endl;
    return 0;
}
 
