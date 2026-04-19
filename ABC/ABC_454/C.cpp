#include <bits/stdc++.h>

std::set<int> S;
std::vector<std::vector<int>> adj; 
std::vector<bool> visited; // visited[cur][prev]

void bfs(int s) {
    std::queue<int> q;
    q.push(s);

    S.insert(s);
    while (!q.empty()) {
        int x = q.front(); q.pop(); 
        for (auto neighbor : adj[x]) {
            if (visited[neighbor]) continue; // ignore if visited
            S.insert(neighbor);
            visited[neighbor] = true; // visited  
            q.push(neighbor);
        }
    }
}

int main() {
    // input
    int N, M;
    std::cin >> N >> M;
    
    adj.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }
    visited.assign(N, false);
    
    // solve
    bfs(0);

    // presentation
    std::cout << (int)S.size() << std::endl;
    return 0;
}
