#include <bits/stdc++.h>

int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> C(H);
    for (int i = 0; i < H; i++) {
        std::cin >> C[i];
    }
    
    int u = 0;
    bool flgu = true;
    while (flgu) {
        for (int j = 0; j < W; j++) 
            if (C[u][j] == '#') flgu = false;
        if (flgu) u++;
    }
        
    int d = H;
    bool flgd = true;
    while (flgd) {
        for (int j = 0; j < W; j++)
            if (C[d - 1][j] == '#') flgd = false;
        if (flgd) d--;
    }

    int l = 0;
    bool flgl = true;
    while (flgl) {
        for (int i = 0; i < H; i++) 
            if (C[i][l] == '#') flgl = false;
        if (flgl) l++;
    }

    int r =  W;
    bool flgr = true;
    while (flgr) {
        for (int i = 0; i < H; i++) 
            if (C[i][r - 1] == '#') flgr = false;
        if (flgr) r--;
    }

    for (int i = 0; i < H; i++) {
        if (i < u || i >= d) continue; // [u, d)
        for (int j = 0; j < W; j++) {
            if (j < l || j >= r) continue; // [l, r)
            std::cout << C[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}
