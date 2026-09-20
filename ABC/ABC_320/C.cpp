#include <bits/stdc++.h>

static const int INF = 300;

int main() {
    int M;
    std::cin >> M;

    std::vector<std::string> S(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> S[i];
        S[i] += S[i] + S[i];
    }

    auto solve = [&](int x, const std::vector<int>& v) -> int {
        int i, j, k;
        bool b1 = false, b2 = false, b3 = false;

        for (i = 0; i < 3 * M; i++) {
            if (S[v[0]][i] - '0' == x) {
                b1 = true;
                break;
            }
        }
        for (j = i + 1; j < 3 * M; j++) {
            if (S[v[1]][j] - '0' == x) {
                b2 = true;
                break;
            }
        }
        for (k = j + 1; k < 3 * M; k++) {
            if (S[v[2]][k] - '0' == x) {
                b3 = true;
                break;
            }
        }

        if (b1 * b2 * b3 != true) return INF;
        else return k;
    };

    int ans = INF;

    std::vector<int> A;
    std::vector<bool> visited(3);
    auto dfs = [&](auto f) -> void {
        if (A.size() == 3) {
            for (int i = 0; i < 10; i++) {
                ans = std::min(ans, solve(i, A));
            }
            return;
        }

        for (int r = 0; r < 3; r++) {
            if (visited[r]) continue;

            visited[r] = true;
            A.push_back(r);
            f(f);
            visited[r] = false;
            A.pop_back(); // revert
        }
    };
    dfs(dfs);

    if (ans == INF) std::cout << -1 << std::endl;
    else std::cout << ans << std::endl;
    
    return 0;
}

