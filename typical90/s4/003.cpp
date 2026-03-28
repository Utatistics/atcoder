#include <iostream>
#include <vector>
#include <utility>

std::pair<int,int> dfs(int x, const std::vector<std::vector<int>> &adj, std::vector<bool> &status, int d, int maxd) {
    status[x] = true;
    std::pair<int,int> p = {d, x}; // default: current node
    for (auto neighbor : adj[x]) {
        if (!status[neighbor]) {
            auto p_current = dfs(neighbor, adj, status, d + 1, maxd);
            if (p_current.first > p.first) {
                p = p_current; // update if deeper
            }
        }
    }
    return p;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) { // assuming tree
        int a, b;
        std::cin >> a >> b;
        --a; --b; // zero-based
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    std::vector<bool> status(N, false);
    auto p1 = dfs(0, adj, status, 0, 0);
    
    status.assign(N, false);
    auto p2 = dfs(p1.second, adj, status, 0, 0);
 
    int ans = p2.first + 1; // diameter length
    std::cout << ans << "\n";

    return 0;
}

