#include <bits/stdc++.h>

using p = std::pair<int, int>;

int main() {
    int N, M;
    std::cin >> N >> M;

    int ans = 0;
    std::set<p> G;
    for (int i = 0; i < M; i++) {
        int r, c;
        std::cin >> r >> c;
        
        bool status = true;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) // O(4 * log M)
                if (G.find({r + i, c + j}) != G.end()) status = false;
        }
        
        if (status) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                 G.insert({r + i, c + j});
            }
        ans++;
        }
    }
    std::cout << ans << std::endl;
    
    return 0;
}
