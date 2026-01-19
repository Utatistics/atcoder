#include <bits/stdc++.h>


static const int INF = 1e9;
using P = std::pair<int, int>;

auto bfs(int s, std::vector<string> &A) {
    // init
    std::vector<int> dx = {-1, 0, 1, 0};
    std::vector<int> dy = {0, 1, 0, -1};
    std::vector<std::vector<int>> d(H * W, std::vector<int>(4, INF));
    std::deque<std::P<int, int>> dq;

    for (int d = 0; d < 4; d++) {
        d[s][d] = 0;
        dq.push_back({s, d});
    }

    while (!dq.empty()) {
        auto p = dq.front();
        dq.pop_front();

        for (auto neighbor : adj[x]) {
            if (status[neighbor]) continue; // ignore if visited
            status[neighbor] = true; // visited
            // logic here
            q.push(neighbor);
        }
    }
    return d;
}

int main () {
    // input processing
    int H, W;
    std::cin >> H >> W;

    int rs, cs, rt, ct;
    std::cin >> rs >> cs >> rt >> ct;
    rs--; cs--; rt--; ct--;
    int s = cs + rs * W; 
    int t = ct + rt * W;

    std::vector<string> A(H * W); // flatten
    for (int i = 0; i < H; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < W; j++)
            A[j + i * W] = s[j];
    }

    // solve
    auto dist = bfs(s, A);
    
    // presentation
    int ans = INF;
    for (int d = 0; i < 4; d++) {
        ans = std::min(ans, dist[t][d]);
        
    }

    return 0;
}
