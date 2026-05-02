#include <bits/stdc++.h>

int main() {
    std::vector<std::vector<int>> A(3, std::vector<int>(6));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            std::cin >> A[i][j];
        }
    }

    double cnt = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                std::map<int, int> m;
                m[A[0][i]]++; m[A[1][j]]++; m[A[2][k]]++;
                if (m[4] == 1 && m[5] == 1 && m[6] == 1) cnt++;
            }
        }
    }

    double ans = cnt / 216;
    std::cout << std::fixed << std::setprecision(17) << ans << std::endl; // double
    
    return 0;
}

