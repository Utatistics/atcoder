#include <bits/stdc++.h>

int main() {
    int N, M, Q;
    std::cin >> N >> M >> Q;

    std::vector<std::set<int>> p(N);

    while (Q--) {
        int t;
        std::cin >> t;

        if (t == 1) { // single permission
            int x, y;
            std::cin >> x >> y;
            x--;

            p[x].insert(y);

        }

        if (t == 2) { // all permission
            int x;
            std::cin >> x;
            x--;
            p[x].insert(0);
        }

        if (t ==3) { // query
            int x, y;
            std::cin >> x >> y;
            x--;

            // presentation
            if (p[x].count(0) || p[x].count(y))
                std::cout << "Yes\n";
            else 
                std::cout << "No\n";
        }
        
    }
    return 0;
}

