#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    int cnt = 0;
    for (int i = 0; i < N; i++) { // '?' to '.' if allowed
        if (S[i] == 'o') {
            ++cnt;
            continue;
        }

        bool l = (i > 0 && S[i - 1] == 'o');
        bool r = (i + 1 < N && S[i + 1] == 'o');

        if (S[i] == '?' && (l || r))
            S[i] = '.';
    }

    std::vector<P> W;
    std::vector<int> id(N, -1);

    for (int i = 0; i < N; i++) {
        if (S[i] != '?') continue;

        int j = i;
        while (j < N && S[j] == '?') {
            id[j] = (int)W.size();
            ++j;
        }

        W.emplace_back(i, j);
        cnt += (j - i + 1) / 2;
        i = j - 1;
    }

    std::string ans = S;
    if (K == 0) {
        for (int i = 0; i < N; i++) {
            if (ans[i] == '?')
                ans[i] = '.';
        }
    } 
    else {
        for (int i = 0; i < N; i++) {
            if (ans[i] != '?') continue;

            auto [l, r] = W[id[i]];

            int x = cnt - (r - l + 1) / 2;

            // maximum o if position i is forced to '.'
            x += (i - l + 1) / 2;
            x += (r - i) / 2;

            if (x >= K)
                ans[i] = '?';
            else
                ans[i] = 'o';
        }
    }

    std::cout << ans << '\n';
}
