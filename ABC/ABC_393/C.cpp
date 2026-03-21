#include <bits/stdc++.h>

int main() {
    // input
    int N, M;
    std::cin >> N >> M;

    int ans = 0;
    std::set<std::set<int>> S;
    for (int i = 0; i < M; i++) {       
        int u, v;
        std::cin >> u >> v;

        // solve
        if (u == v) {
            ans++;
            continue;
        }

        std::set<int> s;
        s.insert(u); // O(log M)
        s.insert(v); 
        if (S.count(s) > 0) ans++; // O(log M)
        else S.insert(s);
    }
    
    // presentation
    std::cout << ans << std::endl;
    return 0;
}

