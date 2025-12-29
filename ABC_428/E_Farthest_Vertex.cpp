#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

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

  std::vector<std::pair<int, int>> ans;
  auto dfs = [&](auto dfs, int sv, int v, int p=-1, int d=0) -> std::pair<int, int> {
    ans[v] = std::max(ans[v], std::pair<int, int>(d,sv));
    std::pair<int, int> res(d, v);
    for (int u : adj[v]) if (u != p) {
      res = std::max(res, dfs(dfs, sv, u, v, d+1));
    }
    return res;
  };

  int a = dfs(dfs, 0, 0).second; // node = 0, dist = d as init
  int b = dfs(dfs, a, a).second;
  dfs(dfs, b, b);

  for (int i = 0; i < N; i++) {
    std::cout << ans[i].second + 1 << '\n';
  }

  return 0;

}
