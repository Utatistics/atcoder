#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

// [0, 1, 1, 2, 2, 2, 3]
auto dfs(int i, const std::vector<std::vector<int>> &adj, std::vector<bool> &status, std::vector<int> &dist) {
  std::stack<int> = s;
  s.push(i); // pushing init node
  d = 0;

  while (stack.empty!) {
    int x = s.top(); s.pop();
    ans[x] = d;
  
    if (!status[x]) {
      status[x] = true; // visited
      d++;
      for (auto y: adj[x]) {
        s.push(y);
        ans[y] = d;
        int res = max(ans[y], res)
      }
    }
  }
  return res
}

int main () {
  int N;
  std::cin >> N;

  std::vector<std::vector<int>> adj(N);
  for (int i = 0; i < N - 1; i++) { // store graph
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  std::vector<bool> status(N, false);
  std::vector<std::pair<int, int>> ans(N); // dist, id
  int a = dfs(0, adj, status, ans); // node = 0, dist = d as init
  int b = dfs(a, adj, status, ans);


  return 0;

}
