#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

static const int MAX = 1e9; // change if required
using P = std::pair<int, int>; // {to, cost} *change if required

auto dijkstra(int s, int t, std::vector<std::vector<P>> &adj) { // O(E * logV)
    int n = adj.size();

    std::vector<int> d(n); // distance array
    for (int i = 0; i < n; i++) d[i] = (i == s) ? 0 : MAX;
    
    std::vector<int> parent(n, -1); // previous node on shortest path
    
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq; // min heap required
    pq.push({0, s}); // (distance, vertex)

    while (!pq.empty()) {
        auto p = pq.top();
        int dist = p.first;
        int u = p.second;
        pq.pop();

        if (dist > d[u]) continue; // skip outdated node
        for (int i = 0; i < (int)adj[u].size(); i++) {
            auto p = adj[u][i];
            int v = p.first; // to
            int c = p.second; // cost
            if (d[u] + c < d[v]) {
                d[v] = d[u] + c; // update
                parent[v] = u; // record path
                pq.push({d[v], v});
            }
        }
    }

    // recontruct path
    std::vector<int> path;
    int v = t;

    while (v != -1) {
        path.push_back(v);
        if (v == s) break;
        v = parent[v];
    }
    std::reverse(path.begin(), path.end());

    return path; // return distance array
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

    std::vector<int> A(H * W);
    for (int i = 0; i < H; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < W; j++) {
            A[j + i * W] = (s[j] == '.') ? 1 : MAX;
        }
    }

    std::vector<std::vector<P>> adj(H * W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int k = j + i * W;
            int dn = (i != 0) ? j + (i - 1) * W : -1;
            int ds = (i < H - 1) ? j + (i + 1) * W : -1;
            int dw = (j != 0) ? (j - 1) + i * W : -1;
            int de = (j < W - 1) ? (j + 1) + i * W : -1;
            
            if (dn >= 0) adj[k].push_back({dn, A[dn]});
            if (ds >= 0) adj[k].push_back({ds, A[ds]});
            if (dw >= 0) adj[k].push_back({dw, A[dw]});
            if (de >= 0) adj[k].push_back({de, A[de]});
        }
    }

    // solve
    auto path = dijkstra(s, t, adj);

    // presentation
    int ans = 0;
    if ((int)path.size() <= 2) std::cout << 0 << std::endl;
    else {
        int i0 = path[0] / W;
        int j0 = path[0] % W; // init
        int i1 = path[1] / W;
        int j1 = path[1] % W; // init
        int dh0 = i1 - i0;
        int dw0 = j1 - j0;
        // advance
        i0 = i1;
        j0 = j1;
        for (int k = 2; k < (int)path.size(); k++) {
            i1 = path[k] / W;
            j1 = path[k] % W;
            int dh1 = i1 - i0;
            int dw1 = j1 - j0;
            if (dh0 != dh1 || dw0 != dw1) ans++;
            // advance
            i0 = i1;
            j0 = j1;
            dh0 = dh1;
            dw0 = dw1;
        }
        std::cout << ans << std::endl;
    }

    return 0;
}
