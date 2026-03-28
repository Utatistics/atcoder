#include <bits/stdc++.h>

using P = std::pair<int, int>;

static const int N = 10;
std::vector<std::string> S;
std::vector<std::vector<bool>> visited;
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};

bool isBound(int i, int j) { return (0 <= i && i < N && 0 <= j && j < N); }

void dfs(int i, int j) {
    if (visited[i][j] || S[i][j] != 'o') return;
    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int id = i + di[k];
        int jd = j + dj[k];

        if (!isBound(id, jd)) continue;
        dfs(id, jd);
    }
}

bool isConnected(const std::vector<std::string>& S) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'o' && !visited[i][j]) return false;
        }
    }
    return true;
}

int main() {
    S.resize(N);
    for (int i = 0; i < N; i++) std::cin >> S[i];

    P x = {-1, -1};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'o') {
                x = {i, j};
                break;
            }
        }
    }

    if (x.first == -1 && x.second == -1) {
        std::cout << "YES\n";
        return 0;
    }

    bool ans = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited.assign(N, std::vector<bool>(N, false)); // init every time
            if (S[i][j] != 'o') {
                S[i][j] = 'o';
                dfs(x.first, x.second);
                S[i][j] = 'x';
            } else {
                dfs(x.first, x.second);
            }
            if (isConnected(S)) {
                ans = true;
                break;
            }
        }
        if (ans) break;
    }

    if (ans) std::cout << "YES\n";
    else std::cout << "NO\n";

    return 0;
}
