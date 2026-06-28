#include <bits/stdc++.h>

static const int MAX = 1e9;

int main() {
    int N;
    std::cin >> N;

    int Mg;
    std::cin >> Mg;
    std::vector<std::set<int>> G(N);
    for (int i = 0; i < Mg; i++) {
        int a, b;
        std::cin >> a >> b;
        --a; --b;
        G[a].insert(b);
        G[b].insert(a);
    }

    int Mh;
    std::cin >> Mh;
    std::vector<std::set<int>> H(N);
    for (int i = 0; i < Mh; i++) {
        int a, b;
        std::cin >> a >> b;
        --a; --b;
        H[a].insert(b);
        H[b].insert(a);
    }

    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int a;
            std::cin >> a;
            A[i][j] = a;
            A[j][i] = a;
        }
    }

    int ans = MAX;
    
    std::vector<int> p(N);
    for (int i = 0; i < N; i++) p[i] = i;

    do {
        int c = 0;
        std::vector<int> inv(N);
        for (int i = 0; i < N; i++) inv[p[i]] = i;

        for (int i = 0; i < N; i++) {

            for (int x : G[i]) {
                if (H[p[i]].count(p[x]) == 0) {
                    c += A[p[i]][p[x]];
                }
            }
            for (int x : H[p[i]]) {
                if (G[inv[p[i]]].count(inv[x]) == 0) {
                    c += A[p[i]][x];
                }
            }
        }

        ans = std::min(ans, c / 2);

    } while (std::next_permutation(p.begin(), p.end()));
    std::cout << ans << std::endl;
    return 0;
}

