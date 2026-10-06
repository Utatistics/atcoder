#include <bits/stdc++.h>

using P = std::pair<int, int>;

// up, down, left, right * not a grid coordinates!
static const int di[4] = {0, 0, -1, 1};
static const int dj[4] = {1, -1, 0, 0};

int main() {
    int N, M, H, K;
    std::cin >> N >> M >> H >> K;

    std::deque<char> S;
    for (int i = 0; i < N; i++) {
        char c;
        std::cin >> c;
        S.push_back(c);
    }

    std::map<P, int> m;
    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        m[{x, y}]++;
    }

    int x = 0, y = 0;
    while (H >= 0 && !S.empty()) {
        if (S.front() == 'U') {
            x += di[0]; y += dj[0];
        }
        else if (S.front() == 'D') {
            x += di[1]; y += dj[1];
        }
        else if (S.front() == 'L') {
            x += di[2]; y += dj[2];
        }
        else { // 'R'
            x += di[3]; y += dj[3];
        }
        S.pop_front();

        --H;
        if (H < 0) break;
        if (H < K && m[std::make_pair(x, y)] > 0) {
            H = K;
            m[std::make_pair(x, y)]--;
        }
    }

    if (S.empty() && H >= 0) std::cout << "Yes\n"; // finised AND alive
    else std::cout << "No\n";

    return 0;
}

