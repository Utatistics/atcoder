#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<int, int>;

int N, M;

// up, down, left, right
static const int di[9] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
static const int dj[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
bool isBound(int i , int j) { return (0 <= i && i < N && 0 <= j && j < N);}

int main() {
    std::cin >> N >> M;

    std::set<P> s;
    for (int k = 0; k < M; k++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        for (int d = 0; d < 9; d++) {
            int i = a + di[d];
            int j = b + dj[d];
            if (isBound(i, j)) s.insert({i, j}); // O(log M)        
        }
    }

    std::cout << 1LL * N * N - (ll)s.size() << std::endl;

    return 0;
}

