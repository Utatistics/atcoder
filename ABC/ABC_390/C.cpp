#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    // input
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<char>> A(H, std::vector<char>(W));
    std::set<int> I, J;
    for (int i = 0; i < H; i++) { // H for rownum
        for (int j = 0; j < W; j++) { // W for colnum
            std::cin >> A[i][j];
            if (A[i][j] == '#') {
                I.insert(i);
                J.insert(j);
            }
        }
    }
    
    // solve
    bool ans = true;
    for (int i = *I.begin(); i <= *I.rbegin(); i++) {
        for (int j = *J.begin(); j <= *J.rbegin(); j++) {
            if (A[i][j] == '.') ans = false;
        }
    }
 
    // presentation
    if (ans) std::cout << "Yes\n";
    else std::cout << "No\n";
    
    return 0;
}

