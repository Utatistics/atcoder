#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N, M;
    std::cin >> N >> M;

    int A = -1, B = -1;
    int aw = 0, bw = 0; // winning counts
    std::vector<int> va(M, 0), vb(M, 0); // 1 if a/b won

    std::vector<std::vector<int>> r(M); // tournament result
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        --a; --b;

        r[i].push_back(a);
        r[i].push_back(b);

        if (i == 0) { // get init
            A = a;
            B = b;
        }
        if (a == A || b == A) {
            ++va[i];
            ++aw;
        }
        if (a == B || b == B) {
            ++vb[i];
            ++bw;
        }
    }

    std::set<std::pair<int, int>> ans;
    auto f = [&](int x, int w, const auto& v) -> void {
        if (w == M) {
            for (int i = 0; i < N; i++) {
                if (i == x) continue;
                ans.insert({std::min(x, i), std::max(x, i)});
            }
        }
        else { // O(N + M)
            std::vector<int> c(N, 0);
            for (int i = 0; i < M; i++) { // consider ith game
                if (v[i] > 0) continue; // x already in
                for (auto y : r[i]) c[y]++;
            }

            for (int y = 0; y < N; y++) { // consider candidates for y
                if (y == x) continue;
                if (c[y] == M - w) {
                    ans.insert({std::min(x, y), std::max(x, y)});
                }
            }
        }
    };

    f(A, aw, va);
    f(B, bw, vb);

    std::cout << ans.size() << std::endl;
    return 0;
}
