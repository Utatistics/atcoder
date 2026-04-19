#include <bits/stdc++.h>

using P = std::pair<char, int>;

void append(std::string &s, char c, int i) {
    for (int j = 0; j < i; j++) s += c;
}

int main() {
    // input
    int N, K;
    std::cin >> N >> K;
    
    std::string S;
    std::cin >> S;

    // solve
    std::queue<P> rle;
    rle.push({S[0], 1});
    for (int i = 1; i < N; i++) {
        if (S[i] == rle.back().first) rle.back().second++;
        else rle.push({S[i], 1});
    }

    std::string ans = "";
    
    int k = 0;
    std::queue<P> q;
    while (!rle.empty()) {
        auto [c, i] = rle.front(); rle.pop();
        if (c == '1') k++;

        if (k == K - 1) {
            append(ans, c, i);
            while (!rle.empty()) {
                auto [d, j] = rle.front(); rle.pop();
                if (d == '0') q.push({d, j});
                else {
                    k++;
                    append(ans, d, j);
                    break;
                }
            }
            while (!q.empty()) {
                auto [d, j] = q.front(); q.pop();
                append(ans, d, j);
            }
        }
        else append(ans, c, i);
    }

    // presentation
    std::cout << ans << std::endl;
    return 0;
}

