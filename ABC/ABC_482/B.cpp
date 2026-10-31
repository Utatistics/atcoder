#include <bits/stdc++.h>

int main() {
    std::vector<std::string> G(5);
    for (int i = 0; i < 5; i++) std::cin >> G[i];
    
    std::vector<int> cnti(5, 0), cntj(5 ,0);
    int cntlr = 0, cntrl = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (G[i][j] == 'o') {
                ++cnti[i];
                ++cntj[j];

                if (i - j == 0) ++cntlr;
                if (i + j == 4) ++cntrl;
            }
        }
    }

    int cnt = 0;

    cnt = std::max(cnt, cntlr);
    cnt = std::max(cnt, cntrl);

    for (int i = 0; i < 5; i++) {
        cnt = std::max(cnt, cnti[i]);
        cnt = std::max(cnt, cntj[i]);
    }
    std::cout << 5 - cnt << std::endl;

    return 0;
}

