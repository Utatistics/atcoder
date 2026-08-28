#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> G(N);
    for (int i = 0; i < N; i++) std::cin >> G[i];
    
    std::vector<int> cnti(N, 0), cntj(N, 0);
    for (int i = 0; i < N; i++) {
       for (int j = 0; j < N; j++) {
           if (G[i][j] == 'o') {
               cnti[i]++;
               cntj[j]++;
           }
       }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
       for (int j = 0; j < N; j++) {
           if (G[i][j] != 'o') continue;
           if (cnti[i] < 2 || cntj[j] < 2) continue;
           ans += (cnti[i] - 1) * (cntj[j] - 1);
       }
    }

    std::cout << ans << std::endl;
    return 0;
}

