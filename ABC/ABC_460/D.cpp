#include <bits/stdc++.h>

int H, W;

// clock wise
static const int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
static const int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> S(H);
    for (int i = 0; i < H; i++) std::cin >> S[i];

    
        
    return 0;
}

