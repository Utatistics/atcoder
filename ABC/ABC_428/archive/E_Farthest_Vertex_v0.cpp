#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

void printDP(const std::vector<int> &dp, int N) {
    std::cout << "DP matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val = dp[i + j * N];
            if (val == -1) std::cout << "x ";  // optional: mark unvisited as x
            else std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

void dfs(int node, int dist, const std::vector<std::vector<int>> &adj, std::vector<int> &dp, std::vector<bool> &status) {
  int n = adj.size();

  if (!status[node]) {
    status[node] = true; // visited
    dist++;
    for (auto neighbor: adj[node]) {
      dp[node + neighbor * n] = dist;
      dfs(neighbor, dist, adj, dp, status);
    } 
  }
}

int main () {
  int N;
  std::cin >> N;

  std::vector<std::vector<int>> adj(N);
  for (int i = 0; i < N - 1; i++) { // store graph:wq
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  std::vector<int>  dp(N * N, -1); // dp with dfsdfs
  for (int i = 0; i < N; i++) {
    std::vector<bool> status(N, false);
    dfs(i, 0, adj, dp, status); // node = 0, dist = d as initprintDP
    printDP(dp, N);
  }

  int md = -1;
  for (int i = 0; i < N; i++) { // presentation 
    for (int j = 0; j < N; j++) {
      md = std::max(md, dp[i + j * N]);
    }
    std::cout << md << "\n";
  }

  return 0;

}

