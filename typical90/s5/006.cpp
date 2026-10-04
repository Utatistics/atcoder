#include <bits/stdc++.h>

static const int INF = 100009;

int main() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    std::vector<std::array<int, 26>> nex(N + 1); // nex[N] as padding
    for (auto& row : nex) row.fill(INF);

    for (int i = N - 1; i >= 0; i--) { // nex[i][c] := first idx of c at/after i
        nex[i] = nex[i + 1];
        nex[i][S[i] - 'a'] = i;
    }

    std::string ans = "";

    int pos = 0;
    while (K > 0) {
        for (int c = 0; c < 26; c++) {
            int idx = nex[pos][c];

            if (idx == INF) continue; // No char at pos onwards
            if (N - idx < K) continue; // N - idx - 1 remaining, K - 1 to cover

            ans += (char)('a' + c);
            pos = idx + 1;
            K--;

            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

// e.g. S = "cabca"
//          a    b    c
// nex[5] INF  INF  INF
// nex[4]  4   INF  INF
// nex[3]  4   INF   3
// nex[2]  4    2    3
// nex[1]  1    2    3
