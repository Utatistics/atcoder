#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> K(N);
    std::vector<std::unordered_map<int, int>> m(N);
    for (int i = 0; i < N; i++) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            std::cin >> a;
            K[i].push_back(a);
            m[i][a]++;
        }
    }

    double ans = 0;
    for (int i = 0; i < N; i++) {
        int M = K[i].size();
        for (int j = i + 1; j < N; j++) {
            int S = K[j].size();

            double p = 0;
            for (int k = 0; k < M; k++) {
                int a = K[i][k];
                p += (1.0 / M) * (1.0 * m[j][a] / S);
            }
            ans = std::max(ans, p);
        }
    }
    
    std::cout << std::fixed << std::setprecision(17) << ans << std::endl; // double 
    return 0;
}

