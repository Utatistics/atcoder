#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<char, int>;

int main() {
    // input processing
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    // solve
    std::vector<P> rle; // run length encoding
    rle.push_back({S[0], 1});
    for (int i = 1; i < N; i++) {
        if (S[i] == rle.back().first) rle.back().second++;
        else rle.push_back({S[i], 1});
    }

    // presentationi
    ll t = 1LL * N * (N + 1) / 2;
    ll ret = 0;
    for (auto p : rle) {
        int d = p.second;
        ret += 1LL * d * (d + 1) / 2;
    }

    std::cout << t - ret << std::endl;

    return 0;
}

