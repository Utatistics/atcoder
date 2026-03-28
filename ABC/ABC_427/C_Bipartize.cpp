#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

int main () {clear
    
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        edges.push_back({--u, --v});
    }

    // bitmask enumeration
    int ans = 1e9;
    for (int i = 0; i < std::pow(2, N); i++) { // ith pattern of coloring
        // decode the int i as the color pattern
        std::vector<int> color(N, 0);
        for (int j = 0; j < N; j++) { 
            if (i >> j & 1) color[j] = 1; // extracts jth bit of i with bit operator 
        }
        // iterate over edges
        int cnt = 0;
        for (auto edge : edges) {
            if ( color[edge.first] == color[edge.second] ) cnt++;
        }
        ans = std::min(cnt, ans);
    }
    std::cout << ans;

    return 0;
}
