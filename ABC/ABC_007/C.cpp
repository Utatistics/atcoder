#include <iostream>
#include <string>
#include <vector>
#include <queue>

void bfs(int s, const std::vector<std::vector<int>> &adj, std::vector<int> &D) {
    std::vector<bool> status((int)D.size());
    std::queue<int> q;

    // init
    status[s] = true;
    q.push(s);
    int d = 0;
    D[s] = d;
    
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto neighbor : adj[x]) {
            if (status[neighbor]) continue; // ignore if visited
            status[neighbor] = true; // visited
            D[neighbor] = D[x] + 1;
            q.push(neighbor);
        }
    }
}

int main () {
    // input processing
    int R, C;
    std::cin >> R >> C;

    int sy, sx, gy, gx;
    std::cin >> sy >> sx >> gy >> gx;
    sy--; sx--; gy--; gx--; // 0 index

    std::vector<char> A(R * C);
    for (int i = 0; i < R; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < C; j++) A[i * C + j] = s[j];
    }

    // solve
    std::vector<std::vector<int>> adj(R * C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int k = i * C + j;
            if (A[k] == '#') continue;
            // get neighbors
            int n = (i == 0) ? -1 : k - C;
            int e = (j == C - 1) ? -1 : k + 1;
            int s = (i == R - 1) ? -1 : k + C;
            int w = (j == 0) ? -1 : k - 1;

            // add if accessible
            if (n >= 0)
                if (A[n] == '.') adj[k].push_back(n);
            if (e >= 0)
                if (A[e] == '.') adj[k].push_back(e);
            if (s >= 0)
                if (A[s] == '.') adj[k].push_back(s);
            if (w >= 0)
                if (A[w] == '.') adj[k].push_back(w);
        }
        
    }
 
    std::vector<int> D(R * C); // distant
    
    bfs(sx + sy * C, adj, D);
    std::cout << D[gx + gy * C] << std::endl;

    return 0;
}
