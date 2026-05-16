#include <bits/stdc++.h>

int main() {
    int X;
    std::cin >> X;
    int Q;
    std::cin >> Q;

    int m = X;
    
    std::multiset<int> s;
    s.insert(X);
    auto it = s.begin(); // at X 
    
    while (Q--) {
        int a, b;
        std::cin >> a >> b;
        s.insert(a);
        s.insert(b);

        int l = 0;
        int r = 0;

        if (a <= m) l++;
        if (b <= m) l++;
        if (a >= m) r++;
        if (b >= m) r++;

        if (l < r) m = *(++it);
        else if (l > r) m = *(--it);
        else m = *(it);

        std::cout << m << "\n";

    }
    return 0;
}

