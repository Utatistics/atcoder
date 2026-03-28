#include <bits/stdc++.h>

static const int MAX = 1e9;
using P = std::pair<int, int>;
using ll = long long;

std::vector<std::vector<P>> adj;

auto dijkstra(int s) {
    int n = adj.size();

    std::vector<int> d(n);
    for (int i = 0; i < n; i++) d[i] = (i == s) ? 0 : MAX;

    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();

        if (dist > d[u]) continue;

        for (auto p : adj[u]) {
            auto [v, c] = p;
            if (d[u] + c < d[v]) {
                d[v] = d[u] + c;
                pq.push({d[v], v});
            }
        }
    }

    return d;
}

int main() {

    int N, M;
    std::cin >> N >> M;

    adj.resize(N);

    for (int i = 0; i < M; i++) {
        int a,b,c;
        std::cin >> a >> b >> c;
        a--; b--;

        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    // init
    std::vector<std::vector<int>> D(N);
    for (int i = 0; i < N; i++) D[i] = dijkstra(i); // O(N * M log N)

    ll S = 0;
    for (int i = 0; i < N; i++) { // O(N^2)
        for (int j = i+1; j < N; j++) {
            S += D[i][j];
        }
    }

    // update
    int K;
    std::cin >> K;
    for (int k = 0; k < K; k++) { // O(K * N^2)
        int x, y, z;
        std::cin >> x >> y >> z;
        x--; y--;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int d0 = D[i][j];
                int d1 = std::min({
                    D[i][j],
                    D[i][x] + z + D[y][j],
                    D[i][y] + z + D[x][j]
                });

                if (d0 > d1) {
                    S += d1 - d0;
                    D[i][j] = d1;
                    D[j][i] = d1;
                }
            }
        }

        // presentation
        std::cout << S << std::endl;
    }

    return 0;
}
