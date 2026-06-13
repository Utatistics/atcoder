#include <bits/stdc++.h>

int main() {
    int H, W, N;
    std::cin >> H >> W >> N;

    std::vector<std::set<int>> s(H + W); // unordered_set will get TLE...
    for (int i = 0; i < N; i++) {
        int r, c;
        std::cin >> r >> c;
        r--; c--;
        s[r].insert(c + H);
        s[c + H].insert(r);
    } // O(N logN)

    int Q;
    std::cin >> Q;
    
    while (Q--) {
        int t;
        std::cin >> t;
        int x;
        std::cin >> x;
        x--;
        
        if (t == 1) { // delete row
            std::cout << s[x].size() << "\n";
            for (int i : s[x]) s[i].erase(x); // O(N * logN)
            s[x].clear();
        }
        else { // delete column
            std::cout << s[x + H].size() << "\n";
            for (int i : s[x + H]) s[i].erase(x + H); // O(N * logN)
            s[x + H].clear();
        }
    }
    return 0;
}
