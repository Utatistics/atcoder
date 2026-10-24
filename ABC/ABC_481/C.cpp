#include <bits/stdc++.h>

int main() {
    int Q;
    std::cin >> Q;

    int i = 1;
    std::map<std::string, int> m;
    
    while (Q--) {
        std::string s;
        std::cin >> s;

        if (m.count(s) == 0) {
            std::cout << i << "\n";
            m[s] = i++;
        }
        else {
            std::cout << m[s] << "\n";
        }
    }
    return 0;
}

