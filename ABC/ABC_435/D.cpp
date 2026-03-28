#include <bits/stdc++.h>

// gloabl
int N, M, Q;
std::vector<std::vector<int>> adj;
std::vector<bool> status;

void bfs(int s) {
    std::queue<int> q;

    status[s] = true;
    q.push(s);

    while (!q.empty()) {
        int x = q.front(); q.pop();

        for (auto neighbor : adj[x]) {
            if (status[neighbor]) continue; // ignore if visited
            status[neighbor] = true; // visited
            // logic here
            q.push(neighbor);
        }
    }
}

int main() {
    // input
    std::cin >> N >> M;

    adj.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        
        adj[v].push_back(u); // inverse
    }
 
    std::cin >> Q;
    
    status.assign(N, false); // 0 for white, 1 for black
    while (Q--) {
        int t, v;
        std::cin >> t >> v;
        v--;

        // solve
        if (t == 1) { // paint it black
            if (!status[v]) bfs(v); // propagate
        }

        // presentation
        if (t == 2) {
            if (status[v]) std::cout << "Yes\n";
            else std::cout << "No\n";
        }
    }

    return 0;
}

