#include <iostream>
#include <vector>

void dfs(int x, std::vector<bool> &s, std::vector<int> &c, const std::vector<std::vector<int>> &adj) {
    if (s[x]) return;
    s[x] = true;

    for (auto v : adj[x]) {
        int color = 1 - c[x]; // 1 -> 0, 0 -> 1
        if (c[v] == -1) c[v] = color;
        dfs(v, s, c, adj);
    }
}

int main () {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }

    // solve
    std::vector<bool> s(N, false); // visited status
    std::vector<int> c(N, -1); // uncolored
    c[0] = 0; // init
    dfs(0, s, c, adj);

    int c0 = 0;
    int c1 = 0;
    for (int i = 0; i < N; i++) (c[i] == 0) ? c0++ : c1++;
    int a = (c0 > c1) ? 0 : 1;
    
    int n = 0;
    for (int i = 0; i < N; i++) if (c[i] == a) {
        std::cout << i + 1 << " ";
        if (++n == N/2) break;
    }

    // // debug
    // std::cout << std::endl;
    // for (int i = 0; i < N; i++) std::cout << c[i] << " "; 
    // std::cout << std::endl;
    // std::cout << "c0=" << c0 << ", c1=" << c1 << std::endl;
    
    return 0;
}

