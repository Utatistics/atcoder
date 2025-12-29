#include <iostream>
#include <vector>

int main() {
    int H, W;
    std::cin >> H >> W;
    
    std::vector<std::string> grid(H);
    for (int i = 0; i < H; i++) std::cin >> grid[i];

    std::vector<std::vector<int>> adj(H * W); // adjacency list: index each cell by (i * W + j)
    std::vector<int> b, w; // black and white cells
    int di[4] = {-1, 1, 0, 0}; int dj[4] = {0, 0, -1, 1}; // |i1 - i2| + |j1 - j2| = 1

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int id = i * W + j; // flat 1D index
            char c = grid[i][j];
            if ( c == '#') b.push_back(id);
            else if ( c == '.' ) w.push_back(id);
            for (int d = 0; d < 4; d++) {
                int ni = i + di[d]; 
                int nj = j + dj[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                    int nid = ni * W + nj;
                    adj[id].push_back(nid);
                }
            }
        }
    }

    // Ulam–Warburton automaton
    for (auto id: w) {
        std::vector<int> neighbors = adj[id];
        
        
    } 

    return 0;
}

