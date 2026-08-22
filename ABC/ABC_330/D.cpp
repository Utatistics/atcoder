#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> G(N);
    for (int i = 0; i < N; i++) std::cin >> G[i];

    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
       for (int j = 0; j < N - 1; j++) {
           int cnt = 0;

           if (G[i][j] == 'o') ++cnt;
           if (G[i][j + 1] == 'o') ++cnt;
           if (G[i + 1][j] == 'o') ++cnt;
           if (G[i + 1][j + 1] == 'o') ++cnt;

           if (cnt == 4) ans += 4;
           else if (cnt == 3) ++ans;
           else continue;
       } 
    }

    std::cout << ans << std::endl;
    return 0;
}

