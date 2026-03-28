#include <bits/stdc++.h>

int main() {
    // iput
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> L(N);
    for (int i = 0; i < N; i++) {
        int l;
        std::cin >> l;
        for (int j = 0; j < l; j++) {
            int x;
            std::cin >> x;
            L[i].push_back(x);
        }
    }
    

    std::unordered_map<int, int> m;
    for (int i = 0; i < N; i++) {
        int M = L[i].size();
        int j = 0;
        bool status = false;
        while (j < M && status == false) {
            int x = L[i][j];
            if (m.find(x) != m.end()) {
                j++;
                continue;
            }
            else {
                m[x]++;
                status = true;
                std::cout << x << std::endl;
            }
        }
        if (!status) std::cout << 0 << std::endl;
    }

    return 0;
}

