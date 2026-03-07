#include <bits/stdc++.h>

// global
int H, W;
std::vector<char> A;
std::map<char, std::vector<int>> m;
std::vector<int> d;

void bfs(int s) {
    std::vector<bool> status((int)d.size());
    std::queue<int> q;
    std::set<char> tp; // BFS internal tp track

    status[s] = true;
    d[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int k = q.front(); q.pop();
        int i = k / W;
        int j = k % W;

        std::vector<int> neighbors; // bypass adj
        if (j > 0 && A[k-1] != '#') neighbors.push_back(k-1);
        if (j < W-1 && A[k+1] != '#') neighbors.push_back(k+1);
        if (i > 0 && A[k-W] != '#') neighbors.push_back(k-W);
        if (i < H-1 && A[k+W] != '#') neighbors.push_back(k+W);

        if (A[k] != '.' && A[k] != '#' && !tp.count(A[k])) {
            for (int x : m[A[k]]) {
                if (x != k) neighbors.push_back(x);
            }
            tp.insert(A[k]);
        }

        for (int v : neighbors) {
            if (!status[v]) {
                status[v] = true;
                d[v] = d[k] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    std::cin >> H >> W;
    A.assign(H * W, '.');

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int k = j + i * W;
            std::cin >> A[k];
            if (A[k] != '.' && A[k] != '#') m[A[k]].push_back(k);
        }
    }

    d.assign(H * W, 0);
    bfs(0);

    int ans = d[H * W - 1];
    if (ans == 0) ans = -1;
    std::cout << ans << std::endl;
}
