#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> m(M, 0);
    std::set<int> s;
    for (int i = 0; i < N; i++) {
        int f;
        std::cin >> f;
        f--;
        m[f]++;
        s.insert(f);
    }

    bool ans1 = true;
    if ((int)s.size() != N) ans1 = false;

    bool ans2 = true;
    for (int i = 0; i < M; i++) {
        if (m[i] == 0) ans2 = false;
    }

    if (ans1) std::cout << "Yes\n";
    else std::cout << "No\n";
    if (ans2) std::cout << "Yes\n";
    else std::cout << "No\n";
    
    return 0;
}
