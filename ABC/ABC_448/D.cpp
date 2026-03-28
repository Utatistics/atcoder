#include <bits/stdc++.h>

// global
int N;
std::vector<int> A; // i -> A[i]
std::vector<std::vector<int>> adj;

std::vector<bool> flg;
std::unordered_map<int, int> cnt; // value -> frequency on current root->u path
int dc = 0; // duplicate counter

void dfs(int u, int p) { // u: curernt node, p: parent
    int a = A[u];

    // enter u (i.e. insert A[u])
    if (cnt[a] == 1) dc++;
    cnt[a]++;

    flg[u] = (dc > 0 ? true : false);
    for (int v : adj[u]) {
        if (v == p) continue; // ignore parent
        dfs(v, u);
    }

    // leave u (i.e. remove A[u])
    cnt[a]--;
    if (cnt[a] == 1) dc--; // no longer a duplicate (i.e. 2 -> 1)
    if (cnt[a] == 0) cnt.erase(a); // optional

    return; // explicit return
}

int main() {
    // input
    std::cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    adj.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // solve
    flg.assign(N, false); // default
    dfs(0, -1); // root has no parent

    // presentation
    for (bool ans : flg) {
        if (ans) std::cout << "Yes\n";
        else std::cout << "No\n";
    }
    return 0;
}
