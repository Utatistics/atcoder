#include <bits/stdc++.h>

int main() {
    // input
    int N;
    std::cin >> N;

    std::map<int, int> m;
    std::map<int, int> id;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        m[a]++;

        id[a] = i + 1; // duplicated a irrevant
    }

    // solve
    std::set<int> s;
    for (auto [k, c] : m) { // O(N * logN)
        if (c == 1) s.insert(k);
    }

    // presentation
    if (s.size() == 0) std::cout << -1 << std::endl;
    else std::cout << id[*s.rbegin()] << std::endl; 

    return 0;
}

